// R-NET
// 0.01. 15th Feb, 2001. James Payne

#include "level.h"
#include "scNodePlace.h"

#include "scLite.h"
#include "scRNET.h"

#include "actor.h"

// externs to make the edicts available locally
//extern gentity_t		*g_entities;
//extern gentity_t	   active_edicts;

// need to change file handling to be within quake-3 standard (for reading)
FILE * scFile;

// current status variables
int scRNET_recording = 0;
int scRNET_playback = 0;
int nodePlaceStatus = 0;

int scRNET_preview = 0;

// preview variables
double curr_filmpos;

int curr_clip = -1;

unsigned char * scFilmBuffer = NULL; // pointer to memory where film data is located
int scFilmBufferPos = 0; // current location in the film buffer
int scFilmLength = 0; // total filelength of current film in memory...

int scFirstFrame = 0;

// rnet film status
scRNetFilm_t scFilm;

// frame number
int scFrameNum = 0;

// store prev-current frame connectivity information
static entityState_t prev_info[MAX_GENTITIES];
static playerState_t prev_ps[MAX_GENTITIES];

static entityState_t curr_info[MAX_GENTITIES];
static playerState_t curr_ps[MAX_GENTITIES];

static int scEntInfo[MAX_GENTITIES];
static int scEntCurr[MAX_GENTITIES];
static int scEntUpdate[MAX_GENTITIES];


scRNetSoundBuffer_t sBuffer;

// chunk of memory for decompressing into
static  unsigned char tempBuffer[sizeof(entityState_t) * 2];


char prev_cs[MAX_CONFIGSTRINGS][1024];

int scNotInit = 1;

int debugStat = 0; // 0 = off, 1 = single frame, 2 = continuous

int debugEntLow = 0;
int debugEntHigh = MAX_GENTITIES;

char * eTypes[20] = {"ET_MODELANIM",
	"ET_PLAYER",
	"ET_ITEM",
	"ET_GENERAL",
	"ET_MISSILE",
	"ET_MOVER",
	"ET_BEAM",
   "ET_MULTIBEAM",
   "ET_SPRITE",
	"ET_PORTAL",
	"ET_EVENT_ONLY",
   "ET_RAIN",
   "ET_LEAF",
	"ET_SPEAKER",
	"ET_PUSH_TRIGGER",
	"ET_TELEPORT_TRIGGER",
   "ET_DECAL",
   "ET_EMITTER",
   "ET_ROPE",
   "ET_EVENTS"};

void scWriteData(void * data, int size)
{
	fwrite(data,size,1,scFile);
}

int scReadData(void * data, int size)
{
	if (scFilmBufferPos + size > scFilmLength) size = scFilmLength - scFilmBufferPos;
	memcpy(data,scFilmBuffer + scFilmBufferPos, size);
	scFilmBufferPos = scFilmBufferPos + size;
	return size;
}

int scLoadFilmData(const char * filename, int sType)
{
	// sType = SCFILM_DISK;
	// or
	// sType = SCFILM_PAK;

	if (scFilmBuffer != NULL)
	{
		free(scFilmBuffer);
	}

	if (sType == SCFILM_DISK)
	{
		FILE * inFile = fopen(filename,"rb");
		if (inFile == NULL) 
		{
			// file not found locally, look for it in the Q3 filesystem...


			scFilmLength = gi.FS_ReadFile( filename, (void **)&scFilmBuffer, qfalse);


			// not found in Q3 filesystem, return error...
			if (scFilmLength == -1) 
			{
				scFilmBuffer = NULL;

				return -1;
			}

			
			scFirstFrame = 1;

			return 0;

		}

		fseek(inFile, 0, SEEK_END);
		scFilmLength = ftell(inFile);
		scFilmBufferPos = 0;
		scFilmBuffer = (unsigned char *)malloc(scFilmLength);
		if (scFilmBuffer == NULL) return -1;
		rewind(inFile);

		fread(scFilmBuffer,scFilmLength,1,inFile);
		fclose(inFile);
	}



	scFirstFrame = 1;

	return 0;
}


float scClipLength(const char * filename)
{
	// returns the length of a clipfile, in seconds
	// returns -1 if the clip file is unavailable for some reason
	if ((scRNET_playback == 1) || (scRNET_recording == 1)) return -1;
	
	
	if (scLoadFilmData(filename, SCFILM_DISK)) return 0;

	
	float len = 0;

	int t;
	unsigned char d = 0;
	unsigned short size;
	static char buffer[16384];

	while ((scReadData(&t,4) == 4)) // there's another block to process... (reading the block header)
	{
		len = len + 0.1;
		scReadData(&buffer,4); // (supposed to be the block size)

		
		while((scReadData(&d,1) > 0) && (d != 255))
		{
		
			if ((d == 1) || (d == 2))
			{
				scReadData(&size,2);
				scReadData(&buffer,2);
				scReadData(&buffer,size);
			}
			if (d == 3)
			{
				scReadData(&size,2);
				scReadData(&buffer,2);
				scReadData(&buffer,size);
			}
			if ((d == 4) || (d == 5)) // keepalive blocks
			{
				scReadData(&buffer,2);
			}
			if (d == 6)
			{
				scRNetSoundInfo_t sInfo;
				scReadData(&sInfo,sizeof(scRNetSoundInfo_t));
				scReadData(&buffer,sInfo.name_length + 1);
			}
		}

	}

	return len;

}

void scCleanClip()
{
	if (scFilmBuffer != NULL) free(scFilmBuffer);
	scFilmBuffer = NULL;
	scFilmLength = 0;
	scFilmBufferPos = 0;
	gentity_t * edict;
	Entity * ent;
	int num;

	for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
	{
		level.next_edict = edict->next;
		ent = edict->entity;
		if ((scEntInfo[ent->entnum] == RNET_ENT_USED) || (scEntInfo[ent->entnum] == RNET_ENT_MOD))
		{
			edict->s.renderfx &= ~RF_DONTDRAW;
		}
	}

	
	for (int k = 0; k < MAX_GENTITIES; k++)
	{
	
		if (scEntInfo[scEntCurr[k]] == RNET_ENT_TEMP)
		{
				// need to delete this model...
			for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
			{
				level.next_edict = edict->next;
				ent = edict->entity;
				if (scEntCurr[k] == ent->entnum)
				{
					ent->PostEvent( EV_Remove, 0 );
				}
			}

		}

		//scEntInfo[k] = 0;

	}
	
}

void scAddSound( vec3_t *org, int entnum, int channel, const char *sound_name, float volume, float min_dist ,int ss)
{

	// need to add this sound info to the rff file if we're recording...

	if (sound_name == NULL) return;

	if (strlen(sound_name) <2) return;
	if (strlen(sound_name) >= 255) return;

	if (scRNET_recording == 1)
	{
		// add this sound to the current rff file...
		// add to sound buffer, then add sounds during the actual recording phase...


		for (int i = 0; i < RNET_MAX_SOUNDBUFFER; i++)
		{
			if (sBuffer.sound[i] == NULL)
			{
				sBuffer.sound[i] = (scRNetSoundInfo_t *)malloc(sizeof(scRNetSoundInfo_t));
				sBuffer.sound[i]->channel = channel;
				sBuffer.sound[i]->entnum = entnum;
				sBuffer.sound[i]->min_dist = min_dist;
				sBuffer.sound[i]->ss = ss;
				if (org != NULL)
				{
					sBuffer.sound[i]->org[0] = *org[0];
					sBuffer.sound[i]->org[1] = *org[1];
					sBuffer.sound[i]->org[2] = *org[2];
				} else
				{
					sBuffer.sound[i]->org[0] = 0;
					sBuffer.sound[i]->org[1] = 0;
					sBuffer.sound[i]->org[2] = 0;
				
				}
				sBuffer.sound[i]->volume = volume;
				sBuffer.sound[i]->name_length = strlen(sound_name);
				sBuffer.sound[i]->name = (char *)malloc(strlen(sound_name) + 1);
				strcpy(sBuffer.sound[i]->name,sound_name);
				return;
			}
		}
	}

}


void scStopRecording()
{

	if ((scRNET_playback == 1) || (scRNET_preview == 1))
	{
		scCleanClip();
	}


	scRNET_recording = 0;
	scRNET_playback = 0;
	//scRNET_preview = 0;
	if (scFile != NULL) fclose(scFile);
	
}

int scPlayFrame()
{

	gentity_t * edict;
	Entity * ent;
	int num;
	int h;

	FILE * piffle = fopen("piffle.txt","at");

	// store of which entities are being updated
	memset(scEntUpdate,0,sizeof(int) * (MAX_GENTITIES));

	if (scFirstFrame == 1)
	{
		memset(scEntInfo,0,sizeof(int) * (MAX_GENTITIES));
		
		for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
		{
			level.next_edict = edict->next; 
			scEntInfo[edict->entity->entnum] = RNET_ENT_USED;
		}

		
		for (int u = 0; u < MAX_GENTITIES; u++)
		{
			scEntCurr[u] = -1;
		}

	
		scFirstFrame = 0;

		// now, when we stop recording, we know which entities we can destroy
		// and which we should just un-hide...

	}
				
	
	if (scReadData(&h,4) != 4) 
	{
		//	we've reached the end of the demo file, so stop playback
		scStopRecording();
		return -1;
	}
	
	scReadData(&h,4); // read the size of the whole block...
	
	// read each info block in turn...
	
	// - if header is a '1' then it's an entity update...
	unsigned char d = 0;
	while(d != 255)
	{
		
		
		scReadData(&d,1);

		
			if (d == 6)
			{
				// it's a sound... play it...
				scRNetSoundInfo_t sInfo;
				scReadData(&sInfo,sizeof(scRNetSoundInfo_t));
				sInfo.name = (char *)malloc(sInfo.name_length + 1);
				scReadData(sInfo.name,sInfo.name_length + 1);

				//( &org, entnum, channel, name, volume, min_dist )
				if (scEntCurr[sInfo.entnum] != -1)
				{
					if (sInfo.ss == 1)
					{
						gi.Sound(&sInfo.org,scEntCurr[sInfo.entnum],sInfo.channel, sInfo.name,sInfo.volume,sInfo.min_dist);
					}
					if (sInfo.ss == 0)
					{
						gi.StopSound(scEntCurr[sInfo.entnum],sInfo.channel);
					}
				}

				free(sInfo.name);
				

			}


		if ((d == 1) || (d == 2))
		{
			
			unsigned short size;
			short e_num;
			scReadData(&size,2);
			scReadData(&e_num,2);
			
			scReadData(&tempBuffer,(int)size);

			if (d == 1)
			{
				compDecompressData((unsigned char *)&tempBuffer,(unsigned char *)&prev_info[e_num],(int)size,sizeof(entityState_t));

				scEntUpdate[e_num] = 1;

				for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
				{
					level.next_edict = edict->next;
					ent = edict->entity;
	
					if ((scEntCurr[e_num] == -1) &&
						(edict->s.modelindex == prev_info[e_num].modelindex) &&
						(edict->s.viewmodelindex == prev_info[e_num].viewmodelindex) &&
						(edict->s.worldmodelindex == prev_info[e_num].worldmodelindex) &&
						(edict->s.eType == prev_info[e_num].eType) &&
						//(edict->s.eFlags == prev_info[e_num].eFlags) &&
						(edict->s.clientNum == prev_info[e_num].clientNum) &&
						(scEntInfo[ent->entnum] == RNET_ENT_USED))
					{
						scEntCurr[e_num] = ent->entnum;
						scEntInfo[ent->entnum] = RNET_ENT_MOD;
					}
				}

				/*
				for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
				{
					level.next_edict = edict->next;
					ent = edict->entity;
	
					if ((scEntCurr[e_num] == -1) &&
						(edict->s.modelindex == 0) &&
						(edict->s.constantLight != 0) &&
						(prev_info[e_num].constantLight != 0) &&
						(prev_info[e_num].modelindex == 0) &&
						(scEntInfo[ent->entnum] == RNET_ENT_USED))
					{
						scEntCurr[e_num] = ent->entnum;
						scEntInfo[ent->entnum] = RNET_ENT_MOD;
					}
				}
				*/


				
				if ((!(prev_info[e_num].renderfx & RF_SKYORIGIN)) && (scEntCurr[e_num] == -1) && ((prev_info[e_num].constantLight == 0) || (prev_info[e_num].modelindex > 0)))
				{
					// no entity found which matches the description...
	
					// create such an entity...
	
					Entity *tempEnt = new Entity();

					fprintf(piffle,"Creating new entity: %i\n",tempEnt->entnum);
	
					if (prev_info[e_num].modelindex > 0)
					{	
						str tempStr;
						
						tempStr = str(prev_cs[CS_MODELS + prev_info[e_num].modelindex]);

						fprintf(piffle,"%s %i\n", prev_cs[CS_MODELS + prev_info[e_num].modelindex], prev_info[e_num].modelindex);

						fflush(piffle);
						tempEnt->setModel(tempStr);
										
				
					}

					//if ((prev_info[e_num].constantLight != 0) && (prev_info[e_num].modelindex == 0))
					//{
						//fprintf(piffle,"(light model)");
						//tempEnt->setModel("models/light_model.tik");
					//}
					//tempEnt->SVFlags(SVF_BROADCAST; // set broadcast so the entity is transmitted

					tempEnt->edict->svflags |= SVF_BROADCAST;
					//tempEnt->sv
					scEntCurr[e_num] = tempEnt->entnum;
					scEntInfo[tempEnt->entnum] = RNET_ENT_TEMP;

					if (!(tempEnt->edict->s.renderfx & RF_SKYORIGIN))
					{
					memcpy(&tempEnt->edict->s,&prev_info[e_num],sizeof(entityState_t));
					}
				} else
				{
					for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
					{
						level.next_edict = edict->next;
						ent = edict->entity;

						if (ent->entnum == scEntCurr[e_num])
						{
							if ( (!(edict->s.renderfx & RF_SKYORIGIN)) && (!(prev_info[e_num].renderfx & RF_SKYORIGIN)))
							{
							memcpy(&edict->s,&prev_info[e_num],sizeof(entityState_t));
							}
						}

					}
				}

				

			}
	
	
			if (d == 2)
			{
				scEntUpdate[e_num] = 1;
				compDecompressData((unsigned char *)&tempBuffer,(unsigned char *)&prev_ps[e_num],(int)size,sizeof(playerState_t));
				//prev_ps[e_num].camera_flags ^= CF_CAMERA_CUT_BIT;
				for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
				{
					level.next_edict = edict->next;
					ent = edict->entity;
					if ((ent->entnum == scEntCurr[e_num]) && (ent->client != NULL))
					{
						memcpy(&ent->client->ps,&prev_ps[e_num],sizeof(playerState_t));
						ent->client->ps.pm_flags |= PMF_NO_PREDICTION;
						ent->client->ps.pm_flags |= PMF_FROZEN;
						ent->client->ps.stats[ STAT_CINEMATIC ] = (1<<0);
						//ent->client->ps.
						
						//ent->client->ps.camera_flags =
						//( ( ent->client->ps.camera_flags & CF_CAMERA_CUT_BIT ) ^ CF_CAMERA_CUT_BIT ) |
						//( ent->client->ps.camera_flags & ~CF_CAMERA_CUT_BIT );

						
					}
				}			
			}
		}

		if (d == 4)
		
		{

			short e_num;
			
			scReadData(&e_num,2);
			scEntUpdate[e_num] = 1;
			for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
			{
				
				level.next_edict = edict->next; 
				if (scEntCurr[e_num] == edict->entity->entnum)
				{
					if ((!(edict->s.renderfx & RF_SKYORIGIN)) && (!(prev_info[e_num].renderfx & RF_SKYORIGIN)))
					{
						memcpy(&edict->s,&prev_info[e_num],sizeof(entityState_t));
					}
			
					//if (edict->client != NULL)
					//{
					//	memcpy(&edict->client->ps,&prev_ps[e_num],sizeof(playerState_t));
					//}
				}
			}



			// just a keepalive for this entity number...
		}
		if (d == 5)
		{
			short e_num;
			
			scReadData(&e_num,2);
				
		
			scEntUpdate[e_num] = 1;
			for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
			{
				
				level.next_edict = edict->next; 
				ent = edict->entity;
				if (scEntCurr[e_num] == edict->entity->entnum)
				{
					
					if (edict->client != NULL)
					{
						memcpy(&edict->client->ps,&prev_ps[e_num],sizeof(playerState_t));
						ent->client->ps.pm_flags |= PMF_NO_PREDICTION;
						ent->client->ps.pm_flags |= PMF_FROZEN;
						ent->client->ps.stats[ STAT_CINEMATIC ] = (1<<0);

//				   ent->client->ps.camera_flags =
      //( ( ent->client->ps.camera_flags & CF_CAMERA_CUT_BIT ) ^ CF_CAMERA_CUT_BIT ) |
      //( ent->client->ps.camera_flags & ~CF_CAMERA_CUT_BIT );

						
					}
				}
			}

		}
	
			// - if header is a '3' then it's a configstring update...
		if (d == 3)
		{
			
			unsigned short len;
			unsigned short c_num;
			scReadData(&len,2);
			scReadData(&c_num,2);
			char charBuffer[1024];
			scReadData(&charBuffer,len);
			
			char * st = gi.getConfigstring(c_num);

			fprintf(piffle,"Old CS: [%s], newCS: [%s]\n",st,charBuffer);
			fflush(piffle);
		
			if ((c_num > 1) && (c_num != CS_SKYINFO))
			{
			if ((strcmp(&st[0],(char *)charBuffer) != 0) && (len > 0))
			{
				gi.setConfigstring(c_num,(char *)charBuffer);
				strcpy(&prev_cs[c_num][0],(char *)charBuffer);
			} else
			{
				strcpy(&prev_cs[c_num][0],&st[0]);						
			}
			}
		

		}

		}
		
		
		
		// set config strings that do not currently hold the value that they are supposed to...
		
		//int h = 0;
		h = 2;
		char * st;
		st = gi.getConfigstring(h);
		while(h < MAX_CONFIGSTRINGS)
		{
			if ((strcmp(&st[0],&prev_cs[h][0]) != 0) && (h > 1) && (h != CS_SKYINFO) && (strlen(prev_cs[h]) > 0))
			{
				
				gi.setConfigstring(h,prev_cs[h]);
				fprintf(piffle,"%i, %s\n",h,prev_cs[h]);
				
			}
			h++;
			fflush(piffle);
			//gi.getConfigstring(f);
			if (h < MAX_CONFIGSTRINGS) st = gi.getConfigstring(h);
		}


		// set parents...

		for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
		{
			level.next_edict = edict->next;
			ent = edict->entity;

			/*int rev = ENTITYNUM_NONE;
			for (int h = 0; h < MAX_GENTITIES; h++)
			{
				if ((scEntCurr[h] == ent->entnum) && 
					(scEntInfo[h] == RNET_ENT_TEMP))rev = h;

				if ((scEntCurr[h] == ent->entnum) && 
					(scEntInfo[h] == RNET_ENT_MOD))rev = h;


			}*/

			edict->s.number = ent->entnum;

			//if ((rev != ENTITYNUM_NONE) && (prev_info[rev].parent != ENTITYNUM_NONE)) edict->s.parent = scEntCurr[prev_info[rev].parent];
			if (edict->s.parent != ENTITYNUM_NONE) edict->s.parent = scEntCurr[edict->s.parent];
			if (edict->s.parent == -1) edict->s.parent = ENTITYNUM_NONE;

		}

		// remove temp models which are no longer in use
		// hide original models which are no longer in use...


		for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
		{
			level.next_edict = edict->next;
			ent = edict->entity;
//			int l;
			if (scEntInfo[ent->entnum] == RNET_ENT_USED)
			{
				edict->s.renderfx |= RF_DONTDRAW;
			}
			if (scEntInfo[ent->entnum] == RNET_ENT_MOD)
			{
				for (int k = 0; k < MAX_GENTITIES; k++)
				{
					if ((scEntUpdate[k] == 0) && (scEntCurr[k] == ent->entnum))
					{
						edict->s.renderfx |= RF_DONTDRAW;
					}
				}
			}
			if (scEntInfo[ent->entnum] == RNET_ENT_TEMP)
			{
				for (int k = 0; k < MAX_GENTITIES; k++)
				{
					if ((scEntUpdate[k] == 0) && (scEntCurr[k] == ent->entnum))
					{
						// if it isn't removed immediately, make sure that it's
						// at least invisible...
						edict->s.renderfx |= RF_DONTDRAW;

						ent->PostEvent( EV_Remove, 0 );
						scEntCurr[k] = -1;
						scEntInfo[scEntCurr[k]] = 0;
					}
				}
			}
		}

		fclose(piffle);
		
		return 0;
}


void scPlayback(const char * filename)
{
	
	if ((scRNET_playback == 0) && (scRNET_recording == 0))
	{
		
		// open input file,
		//scFile = fopen(filename,"rb");

		if (scLoadFilmData(filename,SCFILM_DISK) == -1)
		{
			return;
			
		}
		scRNET_playback = 1;
		
		scFrameNum = 0;
		memset(&prev_info,0,sizeof(entityState_t) * MAX_GENTITIES);
		memset(&prev_cs,0,1024 * MAX_CONFIGSTRINGS);
		memset(&prev_ps,0,sizeof(playerState_t)* MAX_GENTITIES);
	}
}


void scStartRecording(const char * filename)
{
	if ((scRNET_playback == 0) && (scRNET_recording == 0))
	{
		scRNET_recording = 1;
		
		// open output file,
		scFile = fopen(filename,"wb");
		
		scFrameNum = 0;
		
		memset(&prev_info,0,sizeof(entityState_t) * MAX_GENTITIES);
		memset(&prev_cs,0,1024 * MAX_CONFIGSTRINGS);
		memset(&prev_ps,0,sizeof(playerState_t) * MAX_GENTITIES);
	}
}

FILE * deb = NULL;
	
void scDebugEnts()
{
	if (debugStat == 0) return;
	gentity_t * edict;
	Entity * ent;
	int num;

	if (deb == NULL) deb = fopen("ents_debug.txt","at");

	fprintf(deb,"\n");
	fprintf(deb, "Time: %.2f\n",level.time);


	for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
	{
		level.next_edict = edict->next;
		ent = edict->entity;

		if ((ent->entnum >= debugEntLow) && (ent->entnum <= debugEntHigh))
		{
			fprintf(deb,"Entity: %i\n",ent->entnum);
			
			fprintf(deb,"   Type: %s\n",eTypes[edict->s.eType]);
			if (edict->s.modelindex != 0)
			{
				char * st = NULL;
				st = gi.getConfigstring(CS_MODELS + edict->s.modelindex);
				fprintf(deb,"   Model: [%s]\n",st);
			}
			
			fprintf(deb,"   Pos: (%.1f,%.1f,%.1f)\n",edict->s.netorigin[0],edict->s.netorigin[1],edict->s.netorigin[2]);
			fprintf(deb,"   Ang: (%.1f,%.1f,%.1f)\n",edict->s.netangles[0],edict->s.netangles[1],edict->s.netangles[2]);

			
			fprintf(deb,"   RenderFX: ");
			if (edict->s.renderfx & RF_THIRD_PERSON) fprintf(deb,"THIRDPERSON,");
			if (edict->s.renderfx & RF_FIRST_PERSON) fprintf(deb,"FIRST_PERSON,");
			if (edict->s.renderfx & RF_DEPTHHACK) fprintf(deb,"DEPTHHACK,");
			if (edict->s.renderfx & RF_VIEWLENSFLARE) fprintf(deb,"VIEWLENSFLARE,");
			if (edict->s.renderfx & RF_FRAMELERP) fprintf(deb,"FRAMELERP,");
			if (edict->s.renderfx & RF_BEAM) fprintf(deb,"BEAM,");
			if (edict->s.renderfx & RF_DONTDRAW) fprintf(deb,"DONTDRAW,");
			if (edict->s.renderfx & RF_LENSFLARE) fprintf(deb,"LENSFLARE,");
			if (edict->s.renderfx & RF_EXTRALIGHT) fprintf(deb,"EXTRALIGHT,");
			if (edict->s.renderfx & RF_DETAIL) fprintf(deb,"DETAIL,");
			if (edict->s.renderfx & RF_SHADOW) fprintf(deb,"SHADOW,");
			if (edict->s.renderfx & RF_PORTALSURFACE) fprintf(deb,"PORTALSURFACE,");
			if (edict->s.renderfx & RF_SKYORIGIN) fprintf(deb,"SKYORIGIN,");
			if (edict->s.renderfx & RF_SKYENTITY) fprintf(deb,"SKYENTITY,");
			if (edict->s.renderfx & RF_LIGHTOFFSET) fprintf(deb,"LIGHTOFFSET,");
			if (edict->s.renderfx & RF_CUSTOMSHADERPASS) fprintf(deb,"CUSTOMSHADERPASS,");
			if (edict->s.renderfx & RF_MINLIGHT) fprintf(deb,"MINLIGHT,");
			if (edict->s.renderfx & RF_FULLBRIGHT) fprintf(deb,"FULLBRIGHT,");
			if (edict->s.renderfx & RF_LIGHTING_ORIGIN) fprintf(deb,"LIGHTING_ORIGIN,");
			if (edict->s.renderfx & RF_SHADOW_PLANE) fprintf(deb,"SHADOW_PLANE,");
			if (edict->s.renderfx & RF_WRAP_FRAMES) fprintf(deb,"WRAP_FRAMES,");
			if (edict->s.renderfx & RF_PORTALENTITY) fprintf(deb,"PORTALENTITY,");
			if (edict->s.renderfx & RF_DUALENTITY) fprintf(deb,"DUALENTITY,");
			if (edict->s.renderfx & RF_ADDITIVE_DLIGHT) fprintf(deb,"ADDITIVE_DLIGHT,");
			if (edict->s.renderfx & RF_LIGHTSTYLE_DLIGHT) fprintf(deb,"LIGHTSTYLE_DLIGHT,");
			if (edict->s.renderfx & RF_SHADOW_PRECISE) fprintf(deb,"SHADOW_PRECISE,");
			if (edict->s.renderfx & RF_INVISIBLE) fprintf(deb,"INVISIBLE,");
			if (edict->s.renderfx & RF_WEAPONMODEL) fprintf(deb,"WEAPONMODEL,");
			fprintf(deb,"\n");

			fprintf(deb,"\n");
		}
	
	}
	fflush(deb);


	if (debugStat == 1) debugStat = 0;
}

// main update function - should be called every server tick, after the entities have been updated
void scUpdate()
{
	
	static gentity_t * edict;
	static Entity * ent;
	static int num;

	if (nodePlaceStatus == 1) npUpdateCamera();

	liteUpdateLights();

	if (scNotInit == 1)
	{
		for (int j = 0; j < MAX_FILMCLIPS; j++) scFilm.clip[j] = NULL;
		for (j = 0; j < MAX_GENTITIES; j++) scEntInfo[j] = RNET_ENT_NONE;
		for (j = 0; j < RNET_MAX_SOUNDBUFFER; j++)
		{
			sBuffer.sound[j] = NULL;
		}
		scNotInit = 0;
	}
	
	
	if (scRNET_recording == 1)
	{
		scFrameNum ++;
		
		// record block header
		// - just frame number (leave space also for size of frame)
		
		scWriteData(&scFrameNum,4); // write the block header
		scWriteData(&scFrameNum,4); // spacer to be filled with the size of the block... maybe...
		
		
		FILE * test;
		test = fopen("debug.txt","at");

		fprintf(test,"Start\n");
		fflush(test);

		// first up, write out configstring changes...
		int h = 0;
		char * st;
		st = gi.getConfigstring(h);
		while(h < MAX_CONFIGSTRINGS)
		{
			if ((st != NULL) && (st[0] != 0) && (strcmp(&st[0],&prev_cs[h][0]) != 0))
			{

				if (strstr(&st[0],"serverid") != NULL)
				{
					memset(strstr(&st[0],"serverid"),'a',8);
				}

				unsigned char cc = 3; // configstring block
				unsigned short len = (short)(strlen(st) + 1);
				scWriteData(&cc,1);
				scWriteData(&len,2); // length of config string
				unsigned short dd = h;
				scWriteData(&dd,2);  // confing string number
				scWriteData(&st[0],(int)len);
					
				strcpy(&prev_cs[h][0],st);
				printf("Writing configstring block...\n");
				
				
			}
			h++;
			if (h < MAX_CONFIGSTRINGS) st = gi.getConfigstring(h);
		}

		// go through buffered sounds, writing out info...

		for (int sNum = 0; sNum < RNET_MAX_SOUNDBUFFER; sNum++)
		{
			if (sBuffer.sound[sNum] != NULL)
			{
				unsigned char cc = 6;
				scWriteData(&cc,1);

				scWriteData(sBuffer.sound[sNum],sizeof(scRNetSoundInfo_t));
				scWriteData(sBuffer.sound[sNum]->name,sBuffer.sound[sNum]->name_length + 1);

				free(sBuffer.sound[sNum]->name);
				free(sBuffer.sound[sNum]);
				sBuffer.sound[sNum] = NULL;

			}
		}

		// go though entities writing out info...
				
		for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
		{

			level.next_edict = edict->next;
			
			ent = edict->entity;
			
			if ((ent != NULL) && (ent->entnum >= 0) && (ent->entnum < globals.max_entities))
			{
				fprintf(test,"1");
				fflush(test);

			entityState_t te;
			memcpy(&te,&edict->s, sizeof(entityState_t));

			fprintf(test,"2");
				fflush(test);


			//wipeout unneeded info...

			te.mat[0][0] = 0;
			te.mat[1][0] = 0;
			te.mat[2][0] = 0;
			te.mat[0][1] = 0;
			te.mat[1][1] = 0;
			te.mat[2][1] = 0;
			te.mat[0][2] = 0;
			te.mat[1][2] = 0;
			te.mat[2][2] = 0;

			te.quat[0] = 0;
			te.quat[1] = 0;
			te.quat[2] = 0;
			te.quat[3] = 0;

			for (int k = 0; k < NUM_BONE_CONTROLLERS; k++)
			{
				te.bone_quat[k][0] = 0;
				te.bone_quat[k][1] = 0;
				te.bone_quat[k][2] = 0;
				te.bone_quat[k][3] = 0;
			}

			te.angles[0] = 0;
			te.angles[1] = 0;
			te.angles[2] = 0;

			te.origin[0] = 0;
			te.origin[1] = 0;
			te.origin[2] = 0;
			te.origin2[0] = 0;
			te.origin2[1] = 0;
			te.origin2[2] = 0;

			fprintf(test,"3");
				fflush(test);
				

			int s = compCompressData((unsigned char *)&te,(unsigned char *)&prev_info[ent->entnum],(unsigned char *)&tempBuffer,sizeof(entityState_t),sizeof(entityState_t)*2);
			fprintf(test,"4");
			fflush(test);

			//		fprintf(test,"Ent = %i, Size = %i ",num, s);
			if (s == 0)
			{
				// there were no changes to this entity
				// - write out a header which indicates something to that effect
				// unsigned char cc = 0; // no change to entity since last frame
				// scWriteData(&cc,2); // ie, if size = 0, ignore it...
				unsigned char cc = 4; // null block
				short dd = ent->entnum; // entity number
				scWriteData(&cc, 1);
				scWriteData(&dd, 2);
				
			} else
			{
				if (ent->client != NULL) fprintf(test,"(CLIENT)");
				fprintf(test, "Storing changes to entity: %i. Size: %i, ",(int)ent->entnum, (int)s);
				fprintf(test, "Parent: %i\n",prev_info[num].parent);
			
				
	
				// write the entity change header, ie, size of compressed data and entity num
				unsigned char cc = 1; // entity block
				unsigned short ss = (unsigned short)s; // size of update
				short dd = ent->entnum; // entity number
				scWriteData(&cc, 1);
				scWriteData(&ss, 2);
				scWriteData(&dd, 2);
				scWriteData(&tempBuffer,s);
			}
			
			// and update the previous image of the entity...
			fprintf(test,"5");
			fflush(test);

			memcpy(&prev_info[ent->entnum],&te,sizeof(entityState_t));
			fprintf(test,"6");
			fflush(test);


			if (ent->client != NULL)
			{
	//			memcpy(&ent->client->ps,&prev_ps[num],sizeof(playerState_t));
				int s = compCompressData((unsigned char *)&ent->client->ps,(unsigned char *)&prev_ps[ent->entnum],(unsigned char *)&tempBuffer,sizeof(playerState_t),sizeof(entityState_t)*2);
			
			//		fprintf(test,"Ent = %i, Size = %i ",num, s);
				if (s != 0)
				{
				
					fprintf(test, "Storing playerstate info for entity: %i. Size: %i, ",(int)ent->entnum, (int)s);
					//fprintf(test, "Parent: %i\n",prev_ps[numparent);
					
				// write the entity change header, ie, size of compressed data and entity num
					unsigned char cc = 2; // playerstate block
					unsigned short ss = (unsigned short)s; // size of update
					short dd = ent->entnum; // entity number
					scWriteData(&cc, 1);
					scWriteData(&ss, 2);
					scWriteData(&dd, 2);
					scWriteData(&tempBuffer,s);
				} 
				else
				{
					unsigned char cc = 5; // null block
					short dd = ent->entnum; // entity number
					scWriteData(&cc, 1);
					scWriteData(&dd, 2);

				}
				fprintf(test,"7");
			fflush(test);

				memcpy(&prev_ps[ent->entnum],&ent->client->ps,sizeof(playerState_t));
				fprintf(test,"8");
			fflush(test);

			
			}
			}
			
			
		}
		
		
		// write the 'end of block' 
		unsigned char jj = 255;
		scWriteData(&jj,1);

				fprintf(test,"End\n");
		fflush(test);

		
		fclose(test);
		
		
		// record sound info... (where to get sound status from?)
		// are these entities in fact?


	}
	
	if (scRNET_playback == 1)
	{

		level.cinematic = 1;
		gi.cvar_set( "sv_cinematic", "1" );
	
		scFrameNum ++;
		
		scPlayFrame();
		
			
	}


	if (scRNET_preview == 1)
	{
		level.cinematic = 1;
		gi.cvar_set( "sv_cinematic", "1" );
	

		cvar_t * filmpos = gi.cvar("rnet_filmposvalue","",0);

		double fp = filmpos->value + 0.1;
		gi.cvar_set("rnet_filmposvalue",va("%f",fp));


		// now work out which clip this means we should be on...

		double lp = 0;
		double olp = 0;
		int j = 0;
		int error = 0;
		while((lp <= filmpos->value) && (error == 0))
		{
			j ++;
			if (scFilm.clip[j] == NULL) 
			{
				error = 1;
			} else
			{
				olp = lp;
				lp = lp + scFilm.clip[j]->outpoint - scFilm.clip[j]->inpoint;
			}
			
		}
		if (error == 1)
		{
			scRNET_preview = 0;
			curr_filmpos = 0;
			curr_clip = -1;
			scCleanClip();
			return;
		}
		if (curr_clip != j)
		{
//			if (curr_file != NULL) fclose(curr_file);
			//curr_file = fopen(scFilm.clip[j]->filename, "rb");
			//scCleanClip();

			//FILE * deb = fopen("deb.txt","at");

			if (scLoadFilmData(scFilm.clip[j]->filename,SCFILM_DISK) == -1)
			{
				scRNET_preview = 0;
				return;
			}
			memset(prev_info,0,sizeof(entityState_t) * MAX_GENTITIES);
			memset(prev_ps,0,sizeof(playerState_t) * MAX_GENTITIES);
			memset(&prev_cs,0,1024 * MAX_CONFIGSTRINGS);

			//fprintf(deb,"%i, [%s]\n",j,scFilm.clip[j]->filename);
			//fclose(deb);

			curr_clip = j;
			curr_filmpos = 0;

		}

		gi.cvar_set("rnet_currentclip",va("%s(%.1f)",scFilm.clip[j]->filename, curr_filmpos));

		double des_curr_filmpos = fp - olp + scFilm.clip[j]->inpoint;

	
		// play at least one frame...
		
		int first = 1;
			while((curr_filmpos < des_curr_filmpos) || (first == 1))
			{
				first = 0;
				curr_filmpos = curr_filmpos + 0.1;
				// read in a block, and advance the curr_filmpos by 0.1

				double fl = 0;
				for (int j = 1; j < MAX_FILMCLIPS; j++)
				{
					if (scFilm.clip[j] != NULL) fl = fl + (scFilm.clip[j]->outpoint - scFilm.clip[j]->inpoint);
				}
		
				gi.cvar_set("rnet_filmposslider",va("%i",(int)(double)((fp / fl) * 100)));

				if (scPlayFrame() != 0)
				{
					//curr_clip = -1;
					//curr_filmpos = 0;
					//scCleanClip();
					//scRNET_preview = 0;
					des_curr_filmpos = -1; // hack to make sure the while loop ends
				}


			}
		//}

/*
		for (int g = 0; g < MAX_GENTITIES; g++)
		{
			for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
			{
				level.next_edict = edict->next;
				ent = edict->entity;
				if (ent->entnum == scEntCurr[g])
				{
					memcpy(&edict->s,&prev_info[g], sizeof(entityState_t));
					edict->s.number = ent->entnum;
					if (edict->s.parent != ENTITYNUM_NONE) edict->s.parent = scEntCurr[edict->s.parent];
					if (edict->client != NULL)
					{
						memcpy(&edict->client->ps,&prev_ps[g], sizeof(playerState_t));
						ent->client->ps.pm_flags |= PMF_NO_PREDICTION;
						ent->client->ps.pm_flags |= PMF_FROZEN;
						ent->client->ps.stats[ STAT_CINEMATIC ] = (1<<0);
					}
				}
			}
		
			
		}
*/
	}
	scDebugEnts(); // write entity debugging info
	
}

void scWriteRFF()
{
	// writes a new rff file based off the current scFilm structure...

	// go through each file in turn in the scFilm structure,
	// go from start to end of each file - if the time falls within
	// the boundries, compare changes and write the output...

	for (int i = 0; i < MAX_GENTITIES; i++)
	{
		memset(&prev_info[i],0,sizeof(entityState_t));
		memset(&curr_info[i],0,sizeof(entityState_t));
		memset(&prev_ps[i],0,sizeof(playerState_t));
		memset(&curr_ps[i],0,sizeof(playerState_t));
	}


	int update[MAX_GENTITIES];



	cvar_t * rffName;
	rffName = gi.cvar("rnet_rff_filename","",0);

	FILE * nFile;

	FILE * outFile = fopen(rffName->string,"wb");

	if (outFile == NULL) return;

	unsigned char tempBuffer[16384];

	int cs_update[MAX_CONFIGSTRINGS];

	memset(&cs_update,0,4 * MAX_CONFIGSTRINGS);

	unsigned short size;
	short ent_num;

	memset(&update,0,sizeof(int) * MAX_GENTITIES);
	memset(&cs_update,0,sizeof(int) * MAX_CONFIGSTRINGS);

	for (int c = 1; c < MAX_FILMCLIPS; c++)
	{
		for (int i = 0; i < MAX_GENTITIES; i++)
		{
			memset(&curr_info[i],0,sizeof(entityState_t));
			memset(&curr_ps[i],0,sizeof(playerState_t));
		}
		memset(&cs_update,0,4 * MAX_CONFIGSTRINGS);

	
		

		
		if (scFilm.clip[c] != NULL)
		{
			// write the film stuff for this clip...

			// open the file

			nFile = fopen(scFilm.clip[c]->filename,"rb");
			if (nFile == NULL)
			{
				gi.Printf("Error: Clipfile not found: %s\n",scFilm.clip[c]->filename);
				fclose(outFile);
				return;
			}

			double clipTime = 0;

			// loop until end of file, or passed outpoint
			// * read in first eight bytes
			//    - stop if this read operation fails
			while ((fread(&tempBuffer,8,1,nFile) != 0) && (clipTime < scFilm.clip[c]->outpoint))
			{
				// set update flags to zero

				// memset(&update,0,sizeof(MAX_GENTITIES) * 4);

			// * read in block descriptor byte
				clipTime = clipTime + 0.1;
				unsigned char d;

				//gi.Printf("Cliptime: %.2f",clipTime);

				while((fread(&d,1,1,nFile)) && (d != 255))
				{
					if (d == 1)
					{
						// update entitystate info
						fread(&size,2,1,nFile);
						fread(&ent_num,2,1,nFile);
						fread(&tempBuffer,size,1,nFile);

						//gi.Printf("Info: %i, %i",(int)size,(int)ent_num);
						
						compDecompressData((unsigned char *)&tempBuffer,(unsigned char *)&curr_info[ent_num],(int)size,sizeof(entityState_t));

						update[ent_num] = 1;


					}
					if (d == 6)
					{
						scRNetSoundInfo_t * sInfo;
						sInfo = (scRNetSoundInfo_t *)malloc(sizeof(scRNetSoundInfo_t));
						fread(sInfo,sizeof(scRNetSoundInfo_t),1,nFile);
						sInfo->name = (char *)malloc(sInfo->name_length +1);
						fread(sInfo->name,sInfo->name_length + 1, 1, nFile);

						for (int i = 0; i < RNET_MAX_SOUNDBUFFER; i++)
						{
							if (sBuffer.sound[i] == NULL)
							{
								//sBuffer.sound[i] = (scRNetSoundInfo_t *)malloc(sizeof(scRNetSoundInfo_t));
								//scReadData(sBuffer.sound[i],sizeof(scRNetSoundInfo_t));
								//sBuffer.sound[i]->name = (char *)malloc(sBuffer.sound[i]->name_length + 1);
								
								//scReadData(sBuffer.sound[i]->name,sBuffer.sound[i]->name_length + 1);
								sBuffer.sound[i] = sInfo;
						
								i = RNET_MAX_SOUNDBUFFER;
							}
						}


					}
					if (d == 2)
					{
						// update playerstate info
						fread(&size,2,1,nFile);
						fread(&ent_num,2,1,nFile);
						fread(&tempBuffer,size,1,nFile);
						
						compDecompressData((unsigned char *)&tempBuffer,(unsigned char *)&curr_ps[ent_num],(int)size,sizeof(playerState_t));
						update[ent_num] = 1;

					}
					if (d == 3)
					{
						// read in configstring chunk from nFile
						// if there's a change to a configstring, mark it on the list
						// of configstrings to update when we write stuff out

						unsigned short len;
						unsigned short c_num;
						fread(&len,2,1,nFile);
						fread(&c_num,2,1,nFile);
						fread(&prev_cs[c_num],len,1,nFile);

						cs_update[c_num] = 1;
					}
					if ((d == 4) || (d == 5))
					{
						short temp;
						fread(&temp,2,1,nFile);
						update[temp] = 1;
					}
				}
			
				if (clipTime >= scFilm.clip[c]->inpoint)
				{
					// write out block header
					fwrite(&tempBuffer,8,1,outFile);

					// write out changes to configstrings
					for (int cs = 0; cs < MAX_CONFIGSTRINGS; cs++)
					{
						if (cs_update[cs] == 1)
						{
							cs_update[cs] = 0;
							unsigned char cc = 3; // configstring block
							unsigned short len = (short)(strlen(prev_cs[cs]) + 1);
							fwrite(&cc,1,1,outFile);
							fwrite(&len,2,1,outFile); // length of config string
							unsigned short dd = cs;
							fwrite(&dd,2,1,outFile);  // confing string number
							fwrite(&prev_cs[cs],(int)len,1,outFile);
						}
					}
						// for each entity, check for changes, and write the data
					// if there are changes...
					//for (int e = 0; e < MAX_GENTITIES; e++)
					for (short e = MAX_GENTITIES - 1; e >=0; e--)
					{
						if (update[e] == 1)
						{
						int s = compCompressData((unsigned char *)&curr_info[e],(unsigned char *)&prev_info[e],(unsigned char *)&tempBuffer,sizeof(entityState_t),sizeof(entityState_t)*2);
						if (s != 0)
						{
							unsigned char cc = 1; // entitystate block
							unsigned short ss = (unsigned short)s; // size of update
							
							fwrite(&cc, 1,1,outFile);
							fwrite(&ss, 2,1,outFile);
							fwrite(&e, 2,1,outFile);
							fwrite(&tempBuffer,s,1,outFile);
						}
						else
						{
							unsigned char cc = 4; // keepalive block
							fwrite(&cc, 1,1,outFile);
							fwrite(&e, 2,1,outFile);
						}
						memcpy(&prev_info[e],&curr_info[e],sizeof(entityState_t));
						if ((clipTime >= scFilm.clip[c]->outpoint - 0.1) || (clipTime <= scFilm.clip[c]->inpoint + 0.1))
						{
							curr_ps[e].camera_flags ^= CF_CAMERA_CUT_BIT;
						}
						s = compCompressData((unsigned char *)&curr_ps[e],(unsigned char *)&prev_ps[e],(unsigned char *)&tempBuffer,sizeof(playerState_t),sizeof(playerState_t)*2);
						if (s != 0)
						{
							unsigned char cc = 2; // playerstate block
							unsigned short ss = (unsigned short)s; // size of update
							
							fwrite(&cc, 1,1,outFile);
							fwrite(&ss, 2,1,outFile);
							fwrite(&e, 2,1,outFile);
							fwrite(&tempBuffer,s,1,outFile);
						} else
						{
							unsigned char cc = 5; // playerstate block
						
							fwrite(&cc, 1,1,outFile);
							fwrite(&e, 2,1,outFile);
						}

						memcpy(&prev_ps[e],&curr_ps[e],sizeof(playerState_t));

					}
						update[e] = 0;
					}

						// then write out buffered sounds...

					for (int i = 0; i < RNET_MAX_SOUNDBUFFER; i++)
					{
						if (sBuffer.sound[i] != NULL)
						{
							unsigned char cc = 6;
							fwrite(&cc,1,1,outFile);
							fwrite(sBuffer.sound[i],sizeof(scRNetSoundInfo_t),1,outFile);
							fwrite(sBuffer.sound[i]->name,sBuffer.sound[i]->name_length + 1,1,outFile);
							free(sBuffer.sound[i]->name);
							free(sBuffer.sound[i]);
							sBuffer.sound[i] = NULL;
						}
					}
						// then write out configstring changes...					

					// then write out an end of block marker...
				unsigned char hh = 255;
				fwrite(&hh,1,1,outFile);

				} else
				{
				//	gi.Printf("Too early!\n");
				}

				// clear out the sound buffer after each block so that
				// sounds outside of the current frame don't get played
				// but allow 'stopsound' requests to go through...
				for (int i = 0; i < RNET_MAX_SOUNDBUFFER; i++)
				{
					if ((sBuffer.sound[i] != NULL) && (sBuffer.sound[i]->ss == 1))
					{
						free(sBuffer.sound[i]->name);
						free(sBuffer.sound[i]);
						sBuffer.sound[i] = NULL;
					}
				}

				
				

			}
			

			fclose(nFile);
		}
	}
	fclose(outFile);

}


int compCompressData(unsigned char * indata, unsigned char * old_indata, unsigned char * outdata, int inDataSize, int outDataSize)
{
	int odp = 0, idp = 0;
	
	// compressed data format:
	// 0 - 127: that many changed bytes follow (+1)
	// 128 - 255: that many unchanged bytes follow (-127)
	
	int c = 0;
	
	int cc;
	
	while ((idp < inDataSize) && (odp < outDataSize))
	{
		cc = 0;
		while ((indata[idp] == old_indata[idp]) && (cc < 128) && (idp < inDataSize))
		{
			cc++;
			idp++;
		}
		if (cc > 0)
		{
			outdata[odp] = (char)(127 + cc);
			odp ++;
		}
		cc = 0;
		while (((indata[idp] != old_indata[idp]) || (indata[idp+1] != old_indata[idp+1])) && (cc < 128) && (idp < inDataSize))
		{
			cc ++;
			idp++;
		}
		if (cc > 0)
		{
			outdata[odp] = char(-1 + cc);
			odp++;
			memcpy(&outdata[odp], &indata[idp - cc], cc);
			odp = odp + cc;
			c = 1;
		}
	}
	
	if (c == 0) return 0; // return 0 if nothing at all has changed
	
	return odp;
}

int compDecompressData(unsigned char * indata, unsigned char * outdata, int inDataSize, int outDataSize)
{
	int odp = 0, idp = 0;
	
	while (idp < inDataSize)
	{
		if (indata[idp] <= 127)
		{
			int g = (int)((unsigned char)indata[idp]);
			idp ++;
			memcpy(&outdata[odp],&indata[idp], (g + 1));
			idp = idp + g + 1;
			odp = odp + g + 1;
		}
		if (idp < inDataSize)
		{
			if (indata[idp] >=128)
			{
				int g = (int)((unsigned char)indata[idp]);
				idp ++;
				odp = odp + g - 127;
			}
		}
	}
	
	return odp;
}

void scInitCVars()
{
	gi.cvar_set( "rnet_clip1_filename", "null" );
	gi.cvar_set( "rnet_clip2_filename", "null" );
	gi.cvar_set( "rnet_clip3_filename", "null" );
	gi.cvar_set( "rnet_clip4_filename", "null" );
	gi.cvar_set( "rnet_clip5_filename", "null" );

	gi.cvar_set( "rnet_clip1_length", "----" );
	gi.cvar_set( "rnet_clip2_length", "----" );
	gi.cvar_set( "rnet_clip3_length", "----" );
	gi.cvar_set( "rnet_clip4_length", "----" );
	gi.cvar_set( "rnet_clip5_length", "----" );

	gi.cvar_set( "rnet_inclip1", "----" );
	gi.cvar_set( "rnet_inclip2", "----" );
	gi.cvar_set( "rnet_inclip3", "----" );
	gi.cvar_set( "rnet_inclip4", "----" );
	gi.cvar_set( "rnet_inclip5", "----" );

	gi.cvar_set( "rnet_outclip1", "----" );
	gi.cvar_set( "rnet_outclip2", "----" );
	gi.cvar_set( "rnet_outclip3", "----" );
	gi.cvar_set( "rnet_outclip4", "----" );
	gi.cvar_set( "rnet_outclip5", "----" );

	gi.cvar_set( "rnet_selected_filename","null");
	gi.cvar_set( "rnet_selected_length","----");
	gi.cvar_set( "rnet_selected_inpoint","----");
	gi.cvar_set( "rnet_selected_outpoint","----");

	gi.cvar_set( "rnet_filmposvalue","0.00");
	gi.cvar_set( "rnet_currentclip","null");


}

int scGetClipNum(int selnum)
{
	// returns the overall number of the clip number selnum in the clip list window
	return selnum - 1 + scFilm.clipnum;
}

void scUpdateCVars()
{
	int h;

	h = scGetClipNum(1);
	if (scFilm.clip[h] != NULL)
	{
		gi.cvar_set( "rnet_clip1_filename", scFilm.clip[h]->filename );
		gi.cvar_set( "rnet_inclip1", va( "%.2f",scFilm.clip[h]->inpoint ));
		gi.cvar_set( "rnet_outclip1", va( "%.2f",scFilm.clip[h]->outpoint ));
		gi.cvar_set( "rnet_clip1_length", va( "%.2f",scFilm.clip[h]->len ));
	}
	h = scGetClipNum(2);
	if (scFilm.clip[h] != NULL)
	{
		gi.cvar_set( "rnet_clip2_filename", scFilm.clip[h]->filename );
		gi.cvar_set( "rnet_inclip2", va( "%.2f",scFilm.clip[h]->inpoint ));
		gi.cvar_set( "rnet_outclip2", va( "%.2f",scFilm.clip[h]->outpoint ));
		gi.cvar_set( "rnet_clip2_length", va( "%.2f",scFilm.clip[h]->len ));
	}
	h = scGetClipNum(3);
	if (scFilm.clip[h] != NULL)
	{
		gi.cvar_set( "rnet_clip3_filename", scFilm.clip[h]->filename );
		gi.cvar_set( "rnet_inclip3", va( "%.2f",scFilm.clip[h]->inpoint ));
		gi.cvar_set( "rnet_outclip3", va( "%.2f",scFilm.clip[h]->outpoint) );
		gi.cvar_set( "rnet_clip3_length", va( "%.2f",scFilm.clip[h]->len ));
	}
	h = scGetClipNum(4);
	if (scFilm.clip[h] != NULL)
	{
		gi.cvar_set( "rnet_clip4_filename", scFilm.clip[h]->filename );
		gi.cvar_set( "rnet_inclip4", va( "%.2f",scFilm.clip[h]->inpoint) );
		gi.cvar_set( "rnet_outclip4", va( "%.2f",scFilm.clip[h]->outpoint) );
		gi.cvar_set( "rnet_clip4_length", va( "%.2f",scFilm.clip[h]->len ));
	}
	h = scGetClipNum(5);
	if (scFilm.clip[h] != NULL)
	{
		gi.cvar_set( "rnet_clip5_filename", scFilm.clip[h]->filename );
		gi.cvar_set( "rnet_inclip5", va( "%.2f",scFilm.clip[h]->inpoint) );
		gi.cvar_set( "rnet_outclip5", va( "%.2f",scFilm.clip[h]->outpoint) );
		gi.cvar_set( "rnet_clip5_length", va( "%.2f",scFilm.clip[h]->len ));
	}


	cvar_t *sn;
	sn = gi.cvar("rnet_selectednum","",0);
	if ((sn->integer >0) && (sn->integer < 6))
	{
		h = scGetClipNum(sn->integer);
		if (scFilm.clip[h] != NULL)
		{		
			gi.cvar_set("rnet_selected_filename",scFilm.clip[h]->filename);
			gi.cvar_set("rnet_selected_inpoint",va( "%.2f",scFilm.clip[h]->inpoint));
			gi.cvar_set("rnet_selected_outpoint",va( "%.2f",scFilm.clip[h]->outpoint));
			gi.cvar_set( "rnet_selected_length", va( "%.2f",scFilm.clip[h]->len ));

			gi.cvar_set("rnet_selected_inslider",va("%i",(int)((scFilm.clip[h]->inpoint / scFilm.clip[h]->len) * 100)));
			gi.cvar_set("rnet_selected_outslider",va("%i",(int)((scFilm.clip[h]->outpoint / scFilm.clip[h]->len) * 100)));
		}

	}

	gi.cvar_set("rnet_sel1"," ");
	gi.cvar_set("rnet_sel2"," ");
	gi.cvar_set("rnet_sel3"," ");
	gi.cvar_set("rnet_sel4"," ");
	gi.cvar_set("rnet_sel5"," ");

	if (sn->integer == 1) gi.cvar_set("rnet_sel1","  *");
	if (sn->integer == 2) gi.cvar_set("rnet_sel2","  *");
	if (sn->integer == 3) gi.cvar_set("rnet_sel3","  *");
	if (sn->integer == 4) gi.cvar_set("rnet_sel4","  *");
	if (sn->integer == 5) gi.cvar_set("rnet_sel5","  *");
	

}

void scAddClip(const char * filename)
{
	// adds the clip named 'filename' after the currently selected clip...
	// if the file doesn't exist, just don't do it...

	// get the clip length first... and barf out if the file does not exist
	FILE * tFile;
	tFile = fopen(filename,"rb");
	if (tFile == NULL) return;

	fclose(tFile);

	double length = scClipLength(filename);

	cvar_t *sn;
	sn = gi.cvar("rnet_selectednum","",0);
	
	int k = scGetClipNum(sn->integer);

	if (k <= 0)
	{
		scFilm.clip[1] = (scRNetClip_t *)malloc(sizeof(scRNetClip_t));
		strcpy(scFilm.clip[1]->filename,filename);
		gi.cvar_set("rnet_selectednum","1");
		
		scFilm.clipnum = 1;
		scFilm.clip[1]->inpoint = 0;
		scFilm.clip[1]->outpoint = 0;
		scFilm.clip[1]->len = length;
		scUpdateCVars();
		return;
	}

	// okay, clip needs to be added _after_ clip numbered k...

	// so move everything after k forward one...

	for (int j = MAX_FILMCLIPS - 2; j > k; j--)
	{
		scFilm.clip[j+1] = scFilm.clip[j];

	}
	k = k + 1;
	// put new clip in (k+1)
	scFilm.clip[k] = (scRNetClip_t *)malloc(sizeof(scRNetClip_t));
	strcpy(scFilm.clip[k]->filename,filename);
	//scFilm.clipnum = 1;
	scFilm.clip[k]->inpoint = 0;
	scFilm.clip[k]->outpoint = 0;
	scFilm.clip[k]->len = length;
//	gi.cvar_set("rnet_selectednum","1");
	scUpdateCVars();
		
	if (k >= 3) 
	{
	//	scFilm.clipnum = k - 2;
	}

}

void scNewFile()
{
	// starts a new clip list file, and initialises cvars...


	scInitCVars();
	gi.cvar_set("rnet_selectednum","0"); // to begin with, no clip is selected

	for (int j = 0; j < MAX_FILMCLIPS; j++)
	{
		scFilm.clip[j] = NULL;
	}

	scFilm.clipnum = 0;

}

void scSelectClip(int clipnum)
{
	// first up, work out what clip were talking about...

	// then update the cvars to make them relevant to the selected clip
	// also update the 'rnet_selected_clipnum' cvar to be the new number...

	int g = scGetClipNum(clipnum);

	if (scFilm.clip[g] != NULL)
	{
		gi.cvar_set("rnet_selectednum",va("%i",clipnum));
		scUpdateCVars();
	}

}

void scClipListUp()
{
	cvar_t *h;
	h = gi.cvar("rnet_selectednum","",0);
	
	if (scFilm.clipnum == 0) return;
	scFilm.clipnum --;
	if (scFilm.clipnum < 1) 
	{
		scFilm.clipnum = 1;
	} else
	{
		if (h->integer != 5)
		{
			gi.cvar_set("rnet_selectednum",va("%i",(h->integer + 1)));
		}
	
	}
	scUpdateCVars();
}

void scClipListDown()
{
	cvar_t *h;
	h = gi.cvar("rnet_selectednum","",0);

	if (scFilm.clip[scFilm.clipnum + 5] != NULL)
	{
		scFilm.clipnum ++;
		if (h->integer != 1)
		{
			gi.cvar_set("rnet_selectednum",va("%i",(h->integer - 1)));
		}
	}
	scUpdateCVars();
}

void scUpdateSelInOut()
{
	cvar_t *h;
	h = gi.cvar("rnet_selectednum","",0);
	int l = scGetClipNum(h->integer);
	if (scFilm.clip[l] != NULL)
	{
		cvar_t * in, * out;
		in = gi.cvar("rnet_selected_inpoint","",0);
		out = gi.cvar("rnet_selected_outpoint","",0);


		scFilm.clip[l]->inpoint = in->value;
		scFilm.clip[l]->outpoint = out->value;
	}

	scUpdateCVars();
}

void scRemoveSelected()
{

	cvar_t *h;
	h = gi.cvar("rnet_selectednum","",0);
	int l = scGetClipNum(h->integer);
	if (scFilm.clip[l] != NULL)
	{
		free(scFilm.clip[l]);
		for (int j = l; j < MAX_FILMCLIPS -2; j++)
		{
			scFilm.clip[j] = scFilm.clip[j+1];
		}
	}
	scInitCVars();
	gi.cvar_set("rnet_selectednum","0");	
	scUpdateCVars();
}

void scSelectedUp()
{
	cvar_t *h;
	h = gi.cvar("rnet_selectednum","",0);
	int l = scGetClipNum(h->integer);
	if (scFilm.clip[l] != NULL)
	{
		if (l > 1)
		{
			scRNetClip_t * temp = scFilm.clip[l];
			scFilm.clip[l] = scFilm.clip[l - 1];
			scFilm.clip[l - 1] = temp;

			if (h->integer == 1)
			{
				scClipListUp();
					gi.cvar_set("rnet_selectednum",va("%i",(h->integer - 1)));
			} else
			{
				gi.cvar_set("rnet_selectednum",va("%i",(h->integer - 1)));
			}

		}
	}

	
	scUpdateCVars();
}
void scSelectedDown()
{
	
	cvar_t *h;
	h = gi.cvar("rnet_selectednum","",0);
	int l = scGetClipNum(h->integer);
	if (scFilm.clip[l] != NULL)
	{
		if (scFilm.clip[l+1] != NULL)
		{
			scRNetClip_t * temp = scFilm.clip[l];
			scFilm.clip[l] = scFilm.clip[l + 1];
			scFilm.clip[l + 1] = temp;


			if (h->integer == 5)
			{
				scClipListDown();
					gi.cvar_set("rnet_selectednum",va("%i",(h->integer +1)));
			} else
			{
				gi.cvar_set("rnet_selectednum",va("%i",(h->integer +1)));
			}

		}
	}
	
	scUpdateCVars();
}

void scLoadClipFile()
{
	FILE * ff;
	
	cvar_t * f;

	for(int j = 0; j < MAX_FILMCLIPS; j++)
	{
		if (scFilm.clip[j] != NULL)
		{
			free(scFilm.clip[j]);
		}
	}

	scNewFile();

	f = gi.cvar("rnet_cliplist_filename","",0);

	ff = fopen(f->string,"rb");

	if (ff == NULL) return;
	
	scRNetClip_t temp;

	j = 1;
	while(fread(&temp,sizeof(scRNetClip_t),1,ff) != 0)
	{
		scFilm.clip[j] = (scRNetClip_t *)malloc(sizeof(scRNetClip_t));
		memcpy(scFilm.clip[j],&temp,sizeof(scRNetClip_t));
		j++;
	}
	fclose(ff);
	scInitCVars();
	gi.cvar_set("rnet_selectednum","1");
	scFilm.clipnum = 1;
	scUpdateCVars();
}

void scSaveClipFile()
{
	FILE * ff;
	cvar_t * f;
	f = gi.cvar("rnet_cliplist_filename","",0);
	ff = fopen(f->string,"wb");

	if (ff == NULL) return;
	for (int j = 1; j < MAX_FILMCLIPS;j++)
	{
		if (scFilm.clip[j] != NULL)
		{
			fwrite(scFilm.clip[j],sizeof(scRNetClip_t),1,ff);
		}
	}
	fclose(ff);
}

void scUpdateFilmSlider()
{
	cvar_t * fs;
	fs = gi.cvar("rnet_filmposslider","",0);

	double fl = 0;
	for (int j = 1; j < MAX_FILMCLIPS; j++)
	{
		if (scFilm.clip[j] != NULL) fl = fl + (scFilm.clip[j]->outpoint - scFilm.clip[j]->inpoint);
	}

	gi.cvar_set("rnet_filmposvalue",va("%f",(fl / 100) * fs->value));

}

void scPreviewPlay()
{
	if (scRNET_preview == 1) 
	{
		scRNET_preview = 0;
		scCleanClip();
		return;
	}
	if ((scRNET_playback == 1) || (scRNET_recording == 1)) return;


	cvar_t * filmslider = gi.cvar("rnet_filmposslider","",0);
	int fs = filmslider->integer;
	
	double fl = 0;
	for (int j = 1; j < MAX_FILMCLIPS; j++)
	{
		if (scFilm.clip[j] != NULL) fl = fl + (scFilm.clip[j]->outpoint - scFilm.clip[j]->inpoint);
	}
		
	gi.cvar_set("rnet_filmposvalue",va("%f",(double)((((double)fs) / 100) * fl)));


	curr_clip = -1;
	
	scRNET_preview = 1;
}

void scUpdateClipSlider()
{
	// update both the cvars and the film thingy with the new values for in and out points...

	cvar_t * in, * out, * sel;
	in = gi.cvar("rnet_selected_inslider","",0);
	out = gi.cvar("rnet_selected_outslider","",0);
	sel = gi.cvar("rnet_selectednum","",0);

	int l = scGetClipNum(sel->integer);

	if (scFilm.clip[l] != NULL)
	{
		scFilm.clip[l]->inpoint = ((double)(in->integer) / 100) * scFilm.clip[l]->len;
		scFilm.clip[l]->outpoint = ((double)(out->integer) / 100) * scFilm.clip[l]->len;
		if (scFilm.clip[l]->inpoint > scFilm.clip[l]->outpoint)
		{
			scFilm.clip[l]->outpoint = scFilm.clip[l]->inpoint + 0.1;
			if (scFilm.clip[l]->outpoint > scFilm.clip[l]->len)
			{
				scFilm.clip[l]->outpoint = scFilm.clip[l]->outpoint - 0.1;
				scFilm.clip[l]->inpoint = scFilm.clip[l]->inpoint - 0.1;
				
			}
			//gi.cvar_set("rnet_selected_inslider",va("%i",(int)((scFilm.clip[l]->inpoint / scFilm.clip[l]->len) * 100)));
			//gi.cvar_set("rnet_selected_outslider",va("%i",(int)((scFilm.clip[l]->outpoint / scFilm.clip[l]->len) * 100)));
		}

		scUpdateCVars();
	}


}

void scProcCommand(const char * p1, const char * p2)
{
	int p2v = 0;

	if (strlen(p2) > 0)
	{
		p2v = strtol(p2,NULL,10);
	}

	if (strstr(p1,"record") != NULL)
	{
		if (strlen(p2) == 0) 
		{
			gi.Printf("Usage: rnet record <filename>\n");
		} else
		{
			scStartRecording(p2);
		}
	}
	if (strstr(p1,"play") != NULL)
	{
		if (strlen(p2) == 0) 
		{
			gi.Printf("Usage: rnet play <filename>\n");
		} else
		{
			scPlayback(p2);
		}
		
	}
	if (strstr(p1,"stop") != NULL)
	{
		scStopRecording();
	}

	if (strstr(p1,"cliplist_up") != NULL)
	{
		scClipListUp();
	}
	if (strstr(p1,"cliplist_down") != NULL)
	{
		scClipListDown();
	}
	if (strstr(p1,"select_clip1") != NULL)
	{
		scSelectClip(1);
	}
	if (strstr(p1,"select_clip2") != NULL)
	{
		scSelectClip(2);
	}
	if (strstr(p1,"select_clip3") != NULL)
	{
		scSelectClip(3);
	}
	if (strstr(p1,"select_clip4") != NULL)
	{
		scSelectClip(4);
	}
	if (strstr(p1,"select_clip5") != NULL)
	{
		scSelectClip(5);
	}

	if (strstr(p1,"newfile") != NULL)
	{
		scNewFile();
	}

	if (strstr(p1,"savefile") != NULL)
	{
		scSaveClipFile();
	}
	if (strstr(p1,"loadfile") != NULL)
	{
		scLoadClipFile();
	}

	if (strstr(p1,"addclip") != NULL)
	{
		scAddClip(p2);
	}
	
	if (strstr(p1,"updateselinout") != NULL)
	{
		scUpdateSelInOut();
	}

	if (strstr(p1,"selected_remove") != NULL)
	{
		scRemoveSelected();
	}
	if (strstr(p1,"selected_up") != NULL)
	{
		scSelectedUp();
	}
	if (strstr(p1,"selected_down") != NULL)
	{
		scSelectedDown();
	}

	if (strstr(p1,"update_clipslider") != NULL)
	{
		scUpdateClipSlider();
	}

	if (strstr(p1,"writefile") != NULL)
	{
		scWriteRFF();
	}
	
	if (strstr(p1,"update_filmslider") != NULL)
	{
		scUpdateFilmSlider();
	}

	if (strstr(p1,"vcrpause") != NULL)
	{
		scPreviewPlay();
	}

	

	if (strstr(p1, "np_noclip") != NULL)
	{
		npNoclip(p2v);
	}
	if (strstr(p1, "np_speed") != NULL)
	{
		npSpeed(p2v);
	}
	if (strstr(p1, "np_persp") != NULL)
	{
		npPersp(p2v);
	}
	if (strstr(p1, "np_cam") != NULL)
	{
		npCam(p2v);
	}
	if (strstr(p1, "np_updateangles") != NULL)
	{
		npUpdateangles();
	}

	if (strstr(p1, "np_dropcamera") != NULL)
	{
		npDropcamera();
	}

	if (strstr(p1, "np_switchon") != NULL)
	{
		nodePlaceStatus = 1;
	}
	if (strstr(p1, "np_switchoff") != NULL)
	{
		nodePlaceStatus = 0;
		npRemoveLight(); // and remove the glowing light...
	}

	if (strstr(p1, "np_dropmodel") != NULL)
	{
		npDropmodel();
	}

	if (strstr(p1, "np_changemodel") != NULL)
	{
		npChangemodel();
	}

	if (strstr(p1, "np_seldown") != NULL)
	{
		npSelmodel(-1);
	}
	if (strstr(p1, "np_selup") != NULL)
	{
		npSelmodel(1);
	}

	if (strstr(p1,"np_writescript") != NULL)
	{
		npWritescript();
	}

	if (strstr(p1,"np_pickup") != NULL)
	{
		npPickup();
	}

	if (strstr(p1,"lite_create") != NULL)
	{
		liteCreate();
	}
	if (strstr(p1,"lite_seldown") != NULL)
	{
		liteSel(-1);
	}
	if (strstr(p1,"lite_selup") != NULL)
	{
		liteSel(1);
	}
	if (strstr(p1,"lite_setpos") != NULL)
	{
		liteSetpos();
	}

	if (strstr(p1,"lite_updatevals") != NULL)
	{
		liteUpdatevals();
	}
	
	if (strstr(p1,"lite_write") != NULL)
	{
		liteWrite();
	}
	if (strstr(p1,"lite_save") != NULL)
	{
		liteSave();
	}

	if (strstr(p1,"lite_load") != NULL)
	{
		liteLoad();
	}
	if (strstr(p1,"lite_new") != NULL)
	{
		liteNew();
	}

	if (strstr(p1,"lite_remove") != NULL)
	{
		liteRemove();
	}
	
	if (strstr(p1,"lite_reveal") != NULL)
	{
		liteReveal();
	}

	if (strstr(p1,"debug_low") != NULL)
	{
		debugEntLow = p2v;
	}
	if (strstr(p1,"debug_high") != NULL)
	{
		debugEntHigh = p2v;
	}
	if (strstr(p1,"debug_frame") != NULL)
	{
		debugStat = 1;
	}
	if (strstr(p1,"debug_on") != NULL)
	{
		debugStat = 2;
	}
	if (strstr(p1,"debug_off") != NULL)
	{
		debugStat = 0;
	}
}


