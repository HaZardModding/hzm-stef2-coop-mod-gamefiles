#include "level.h"
#include "scNodePlace.h"
#include "player.h"

#include "scRNET.h"


//extern gentity_t		*g_entities;
//extern gentity_t	   active_edicts;

static scNodePlace_t npInfo;

int firstUpdate = 0;

Entity * npChar;

Entity * cent;

void npUpdateCamera()
{
	// moves the camera position and sets any cvars needed, based on the current npInfo


	//  find the client entity...
	gentity_t * edict;
	Entity * ent;
	gclient_t * client = NULL;
	int num;

	vec3_t camPos;
	vec3_t playPos;
	vec3_t delta_position;
	vec3_t refdef;


	
	for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
	{
		level.next_edict = edict->next;
		ent = edict->entity;
		if (ent->client != NULL) 
		{
			client = ent->client;
			cent = ent;
		}
	}

	if ( !client )
		return;

	if (firstUpdate == 0)
	{
		firstUpdate = 1;
		// create the player entity
		npChar = new Entity();


		npChar->setModel(cent->model);

		npInfo.noclip = 0;
		npInfo.speed = 0;
		npInfo.persp = 0;
		npInfo.camfix = 0;

		npInfo.cams = 0;
		npInfo.mods = 0;
		npInfo.curMod = 0;
		npInfo.dropmodelnext = 0;

		memcpy(&npChar->edict->s,&cent->edict->s,sizeof(entityState_t));
		npChar->edict->s.number = npChar->entnum;
		npChar->edict->s.renderfx |= RF_DONTDRAW;	
	
	}

	gi.cvar_set("rnet_np_cameranum",va("(%i)",npInfo.cams));

	if (npInfo.curMod < npInfo.mods)
	{
		gi.cvar_set("rnet_np_modelinfo",va("(%i): %s",npInfo.curMod, G_GetEntity(npInfo.modNum[npInfo.curMod])->model.c_str()));
	} else
	{
		gi.cvar_set("rnet_np_modelinfo","---");
	}

	VectorCopy(cent->edict->s.angles,npChar->edict->s.angles);
	VectorCopy(cent->edict->s.origin,npChar->edict->s.origin);
	VectorCopy(cent->edict->s.netangles,npChar->edict->s.netangles);
	VectorCopy(cent->edict->s.netorigin,npChar->edict->s.netorigin);


	

	if (npInfo.persp == 1)
	{ // we're in third person mode

	client->ps.pm_flags |= PMF_CAMERA_VIEW;
	//client->ps.camera_flags |= CF_CAMERA_ANGLES_ALLOWOFFSET;
	client->ps.fov = (float)npInfo.fv;

	//client->ps.camera_offset[YAW] = npInfo.yaw;
	//client->ps.camera_offset[PITCH] = npInfo.pitch;

	client->ps.camera_origin[0] = client->ps.origin[0] + npInfo.dist * sin(DEG2RAD(npInfo.yaw- cent->angles[1] + 90));
	client->ps.camera_origin[1] = client->ps.origin[1] + npInfo.dist * cos(DEG2RAD(npInfo.yaw- cent->angles[1] + 90));
	client->ps.camera_origin[2] = client->ps.origin[2] + npInfo.dist * sin(DEG2RAD(npInfo.pitch )) + client->ps.viewheight;


	camPos[0] = client->ps.camera_origin[0];
	camPos[1] = client->ps.camera_origin[1];
	camPos[2] = client->ps.camera_origin[2];

	playPos[0] = client->ps.origin[0];
	playPos[1] = client->ps.origin[1];
	playPos[2] = client->ps.origin[2] + client->ps.viewheight;
	
	VectorSubtract(playPos, camPos, delta_position );
    vectoangles( delta_position, refdef);

	client->ps.camera_angles[0] = refdef[0];
	client->ps.camera_angles[1] = refdef[1];
	client->ps.camera_angles[2] = refdef[2];

	cent->edict->s.renderfx |= RF_DONTDRAW;	

	//if (cent->model != npChar->model) cent->setModel(npChar->model);
	
	//strncpy(client->pers.dm_playermodel,npChar->model.c_str(),sizeof(npChar->model.c_str()));
	cent->animate->ClearLegsAnim();
	cent->animate->ClearTorsoAnim();

	cent->animate->RandomAnimate("idle",NULL);

	//int mi = npChar->edict->s.modelindex;
	//int an = npChar->edict->s.anim;
	//int fr = npChar->edict->s.frame;
	//memcpy(&npChar->edict->s,&cent->edict->s,sizeof(entityState_t));
	//npChar->edict->s.modelindex = mi;
	//npChar->edict->s.anim = an;
	//npChar->edict->s.frame = fr;
		
	

	npChar->edict->s.number = npChar->entnum;
	npChar->edict->s.renderfx &= ~RF_DONTDRAW;	

	if (npInfo.camfix == 0)
	{
		npInfo.camX = camPos[0];
		npInfo.camY = camPos[1];
		npInfo.camZ = camPos[2];
		npInfo.camP = refdef[0];
		npInfo.camYAW = refdef[1];
		npInfo.camR = refdef[2];
	}

	} else // we're in first person mode...
	{
		npChar->edict->s.renderfx |= RF_DONTDRAW;	
		//if (npInfo.camfix == 1)
		//{
		npInfo.camX = client->ps.origin[0];
		npInfo.camY = client->ps.origin[1];
		npInfo.camZ = client->ps.origin[0] + client->ps.viewheight;
		npInfo.camP = client->cmd_angles[0];
		npInfo.camYAW = client->cmd_angles[1];
		npInfo.camR = client->cmd_angles[2];
		//}
	}

	if (npInfo.noclip == 1)
	{
		Player *player = ( Player * )cent;
		player->setMoveType( MOVETYPE_NOCLIP );
	} else
	{
		Player *player = ( Player * )cent;
		player->setMoveType( MOVETYPE_WALK );
	}


	if ((npInfo.camfix == 1) && (npInfo.persp == 1)) // only works in first person mode...
	{ // we're following the player rather than updating the camera position
		client->ps.pm_flags |= PMF_CAMERA_VIEW;
		client->ps.camera_origin[0] = npInfo.camX;
		client->ps.camera_origin[1] = npInfo.camY;
		client->ps.camera_origin[2] = npInfo.camZ;
		camPos[0] = client->ps.camera_origin[0];
		camPos[1] = client->ps.camera_origin[1];
		camPos[2] = client->ps.camera_origin[2];

		playPos[0] = client->ps.origin[0];
		playPos[1] = client->ps.origin[1];
		playPos[2] = client->ps.origin[2] + client->ps.viewheight;
	
		VectorSubtract(playPos, camPos, delta_position );
		vectoangles( delta_position, refdef);

		client->ps.camera_angles[0] = refdef[0];
		client->ps.camera_angles[1] = refdef[1];
		client->ps.camera_angles[2] = refdef[2];

		npInfo.camX = camPos[0];
		npInfo.camY = camPos[1];
		npInfo.camZ = camPos[2];
		npInfo.camP = refdef[0];
		npInfo.camYAW = refdef[1];
		npInfo.camR = refdef[2];
	

	} 


	for (int k = 0; k < npInfo.mods; k++)
	{
		Entity * myEnt = G_GetEntity(npInfo.modNum[k]);
		memcpy(&myEnt->edict->s,&npInfo.modInfo[k],sizeof(entityState_t));
		myEnt->edict->s.number = myEnt->entnum;

		if (k == npInfo.curMod)
		{
			float rc,gc,bc,rad;
			rc = 0.3;
			gc = 0.3;
			bc = 1;
			rad = 120;
			G_SetConstantLight(&npInfo.modInfo[k].constantLight,&rc,&gc,&bc,&rad);
		} else
		{
			float rc,gc,bc,rad;
			rc = 0;
			gc = 0;
			bc = 0;
			rad = 0;
			G_SetConstantLight(&npInfo.modInfo[k].constantLight,&rc,&gc,&bc,&rad);
		
		}

	}

	if (npInfo.dropmodelnext == 1)
	{
		npInfo.dropmodelnext = 0;
		Entity * newEnt;
		newEnt = new Entity();
		newEnt->setModel(npChar->model);
		memcpy(&npInfo.modInfo[npInfo.mods],&npChar->edict->s,sizeof(entityState_t));
		npInfo.modNum[npInfo.mods] = newEnt->entnum;

		npInfo.modInfo[npInfo.mods].renderfx &= ~RF_DONTDRAW;	

		npInfo.modInfo[npInfo.mods].netangles[0] = cent->angles[0];
		npInfo.modInfo[npInfo.mods].netangles[1] = cent->angles[1];
		npInfo.modInfo[npInfo.mods].netangles[2] = cent->angles[2];

		npInfo.modInfo[npInfo.mods].netorigin[0] = cent->origin[0];
		npInfo.modInfo[npInfo.mods].netorigin[1] = cent->origin[1];
		npInfo.modInfo[npInfo.mods].netorigin[2] = cent->origin[2];


		npInfo.mods ++;




		/*
		float r,g,b,rad;
		r = 1;
		g = 0.2;
		b = 0.2;
		rad = 2000;

		G_SetConstantLight(&npInfo.modInfo[npInfo.mods].constantLight,&r,&g,&b,&rad);
		npInfo.mods ++;
		*/


		//Entity * l;

		//l = new Entity();

		
		//G_SetConstantLight(&npInfo.modInfo[npInfo.mods].constantLight,&r,&g,&b,&rad);

		//Event *e = new Event( EV_SetLight );
		//e->AddString( "1.0 0.2 0.2 100" );
		//l->PostEvent( e, 1 );

		//Event *d = new Event( EV_LightOn );
		//l->PostEvent( d, 1 );

		//l->origin.x = cent->origin.x;
		//l->origin.y = cent->origin.y;
		//l->origin.z = cent->origin.z;

		

		//l->SetLight
/*
		e = new Event(EV_LightRadius);
		e->AddString( "100" );
		newEnt->PostEvent( e, 0 );

		e = new Event(EV_LightRed);
		e->AddString( "1.0" );
		newEnt->PostEvent( e, 0 );

		e = new Event(EV_LightGreen);
		e->AddString( "0.2" );
		newEnt->PostEvent( e, 0 );
*/



	}
		
}

void npNoclip(int v)
{
	npInfo.noclip = v;
}

void npSpeed(int v)
{
	npInfo.speed = v;
}

void npPersp(int v)
{
	npInfo.persp = v;
}

void npCam(int v)
{
	npInfo.camfix = v;
}

void npUpdateangles()
{
	cvar_t *dist, *pitch, *yaw, *fov;
	dist = gi.cvar("rnet_np_dist","",0);
	pitch = gi.cvar("rnet_np_pitch","",0);
	yaw = gi.cvar("rnet_np_yaw","",0);
	fov = gi.cvar("rnet_np_fov","",0);

	npInfo.dist = dist->integer;
	npInfo.yaw = yaw->value;
	npInfo.pitch = pitch->value;
	npInfo.fv = fov->value;


	npUpdateCamera();
}

void npDropcamera()
{
	// adds the current camera position to the dropped cameras list...

	npInfo.camPlace[npInfo.cams][0] = npInfo.camX;
	npInfo.camPlace[npInfo.cams][1] = npInfo.camY;
	npInfo.camPlace[npInfo.cams][2] = npInfo.camZ;
	npInfo.camAng[npInfo.cams][0] = npInfo.camP;
	npInfo.camAng[npInfo.cams][1] = npInfo.camYAW;
	npInfo.camAng[npInfo.cams][2] = npInfo.camR;
	npInfo.camFov[npInfo.cams] = npInfo.fv;

	Entity * newEnt = new Entity();

	newEnt->origin.x = npInfo.camX;
	newEnt->origin.y = npInfo.camY;
	newEnt->origin.z = npInfo.camZ;

	newEnt->angles.x = npInfo.camP;
	newEnt->angles.y = npInfo.camYAW;
	newEnt->angles.z = npInfo.camR;

	npInfo.cams ++;

}

void npDropmodel()
{
	// create a new entity with the current player model settings...


	npInfo.dropmodelnext = 1;

}

void npRemoveLight()
{
	for (int k = 0; k < npInfo.mods; k++)
	{
		Entity * myEnt = G_GetEntity(npInfo.modNum[k]);
		

		float rc,gc,bc,rad;
		rc = 0;
		gc = 0;
		bc = 0;
		rad = 0;
		G_SetConstantLight(&npInfo.modInfo[k].constantLight,&rc,&gc,&bc,&rad);
		

		memcpy(&myEnt->edict->s,&npInfo.modInfo[k],sizeof(entityState_t));
		myEnt->edict->s.number = myEnt->entnum;
		myEnt->edict->s.renderfx |= RF_DONTDRAW;

		
	}
	npChar->edict->s.renderfx |= RF_DONTDRAW;
}

void npSelmodel(int g)
{
	if (npInfo.mods == 0) return;
	npInfo.curMod = npInfo.curMod + g;
	npInfo.curMod = npInfo.curMod % npInfo.mods;
}

void npChangemodel()
{

	
	cvar_t * modname = gi.cvar("rnet_np_modelfile","",0);
	str kk = modname->string;
	str tt = "models/"+kk;
	//npChar->setModel(tt);

	delete npChar;

	npChar  = new Entity();

	npChar->setModel(tt);

	
}


void npPickup()
{
	if (npInfo.mods > 0)
	{
		cent->origin.x = npInfo.modInfo[npInfo.curMod].netorigin[0];
		cent->origin.y = npInfo.modInfo[npInfo.curMod].netorigin[1];
		cent->origin.z = npInfo.modInfo[npInfo.curMod].netorigin[2];
		cent->angles.x = npInfo.modInfo[npInfo.curMod].netangles[0];
		cent->angles.y = npInfo.modInfo[npInfo.curMod].netangles[1];
		cent->angles.z = npInfo.modInfo[npInfo.curMod].netangles[2];

		Entity * oldEnt = G_GetEntity(npInfo.modNum[npInfo.curMod]);
		delete oldEnt;

		npChar->origin.x = cent->origin.x;
		npChar->origin.y = cent->origin.y;
		npChar->origin.z = cent->origin.z;
		npChar->angles.x = cent->angles.x;
		npChar->angles.y = cent->angles.y;
		npChar->angles.z = cent->angles.z;

		for (int j = npInfo.curMod; j < npInfo.mods - 1; j++)
		{
			memcpy(&npInfo.modInfo[j],&npInfo.modInfo[j+1], sizeof(entityState_t));
			npInfo.modNum[j] = npInfo.modNum[j+1];
			npInfo.modPlace[j][0] = npInfo.modPlace[j+1][0];
			npInfo.modPlace[j][1] = npInfo.modPlace[j+1][1];
			npInfo.modPlace[j][2] = npInfo.modPlace[j+1][2];
		}
		npInfo.mods --;
		npInfo.curMod = 0;
	}

	
}



void npWritescript()
{
	cvar_t * fn = gi.cvar("rnet_np_scriptfile","",0);
	str ss = fn->string;

	str nfn = ss + "_camera.cam";

	FILE * oFile; 
	if (npInfo.cams > 1)
	{
	oFile =	fopen(nfn.c_str(),"wt");
	
	
	if (oFile == NULL) return;

	//str mn = G_GetEntity(npInfo.c
	int c = 0;

	fprintf(oFile,"spawn Splinepath targetname camnode target camnode_1 origin ""%.2f %.2f %.2f"" angles ""%.2f %.2f %.2f"" speed 1.0 fadetime -1.0 fov %i\n", npInfo.camPlace[c][0], npInfo.camPlace[c][1], npInfo.camPlace[c][2], npInfo.camAng[c][0], npInfo.camAng[c][1], npInfo.camAng[c][2], npInfo.camFov[c]);
	for (int k = 1; k < npInfo.cams -1; k++)
	{
		c = k;
		fprintf(oFile,"spawn Splinepath targetname camnode_%i target camnode_%i origin ""%.2f %.2f %.2f"" angles ""%.2f %.2f %.2f"" speed 1.0 fadetime -1.0 fov %i\n", k, k+1, npInfo.camPlace[c][0], npInfo.camPlace[c][1], npInfo.camPlace[c][2], npInfo.camAng[c][0], npInfo.camAng[c][1], npInfo.camAng[c][2], npInfo.camFov[c]);
		
	}
	c = npInfo.cams-1;
	fprintf(oFile,"spawn Splinepath targetname camnode_%i origin ""%.2f %.2f %.2f"" angles ""%.2f %.2f %.2f"" speed 1.0 fadetime -1.0 fov %i\n", c, npInfo.camPlace[c][0], npInfo.camPlace[c][1], npInfo.camPlace[c][2], npInfo.camAng[c][0], npInfo.camAng[c][1], npInfo.camAng[c][2], npInfo.camFov[c]);


	fclose(oFile);
	}

	if (npInfo.mods == 0) return;

	int nn = 0;
	Entity * ent, * sel;
	sel = G_GetEntity(npInfo.modNum[npInfo.curMod]);
	for (int j = 0; j < npInfo.mods; j++)
	{
		ent = G_GetEntity(npInfo.modNum[j]);
		if (ent->model == sel->model) nn++;
		
	}

	if (nn < 2) return;

	nfn = ss + "_model.cam";

	oFile = fopen(nfn.c_str(),"wt");

	int mnn = nn - 1;
	nn = 0;

	for (j = 0; j < npInfo.mods; j++)
	{
		ent = G_GetEntity(npInfo.modNum[j]);
		if (ent->model == sel->model) 
		{
			if (nn == 0)
			{
				// initial case
				fprintf(oFile,"spawn Splinepath targetname %s target %s_1 origin ""%.2f %.2f %.2f"" angles ""%.2f %.2f %.2f"" speed 1.0 fadetime -1.0\n", ent->model.c_str(),ent->model.c_str(), ent->origin.x, ent->origin.y, ent->origin.z, ent->angles.x, ent->angles.y, ent->angles.z);
			} else 
			{
				if (nn == mnn)
				{
					// end case
					fprintf(oFile,"spawn Splinepath targetname %s_%i origin ""%.2f %.2f %.2f"" angles ""%.2f %.2f %.2f"" speed 1.0 fadetime -1.0\n",ent->model.c_str(), nn, ent->origin.x, ent->origin.y, ent->origin.z, ent->angles.x, ent->angles.y, ent->angles.z);
				}
					else
				{
						// normal case
					fprintf(oFile,"spawn Splinepath targetname %s_%i target %s_%i origin ""%.2f %.2f %.2f"" angles ""%.2f %.2f %.2f"" speed 1.0 fadetime -1.0\n",ent->model.c_str(),nn,ent->model.c_str(), nn+1,ent->origin.x, ent->origin.y, ent->origin.z, ent->angles.x, ent->angles.y, ent->angles.z);
				}
			}


			nn++;
		}
		
	}


	fclose(oFile);

	
	

}