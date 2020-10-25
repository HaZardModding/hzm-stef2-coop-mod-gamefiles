#include "level.h"
#include "scLite.h"
#include "player.h"
#include "misc.h"
#include "../qcommon/qfiles.h"

//#include "entity.h"
//#include "worldspawn.h"
//#include "scriptmaster.h"
//#include "sentient.h"
//#include "misc.h"
//#include "specialfx.h"
//#include "object.h"
//#include "player.h"
//#include "weaputils.h"
//#include "soundman.h"
//#include "../qcommon/qfiles.h"

#include "scRNET.h"


//extern gentity_t		*g_entities;
//extern gentity_t	   active_edicts;

int initLite = 0;


static liteInfo_t lInfo;

int lBlink = 0;

void liteReveal()
{
	lBlink = 0;
}

void liteUpdateLights()
{
	if (initLite == 0)
	{
		initLite = 1;
		memset(&lInfo,0,sizeof(liteInfo_t));
	}

	lBlink ++;

	for (int e = 0; e < MAX_LITES; e++)
	{
		if (lInfo.active[e] == 1)
		{
			Entity * l = G_GetEntity(lInfo.liteNum[e]);
			l->edict->s.netorigin[0] = lInfo.pos[e][0];
			l->edict->s.netorigin[1] = lInfo.pos[e][1];
			l->edict->s.netorigin[2] = lInfo.pos[e][2];

			l->edict->s.origin[0] = lInfo.pos[e][0];
			l->edict->s.origin[1] = lInfo.pos[e][1];
			l->edict->s.origin[2] = lInfo.pos[e][2];

			G_SetConstantLight(&l->edict->s.constantLight,&lInfo.col[e][0],&lInfo.col[e][1],&lInfo.col[e][2],&lInfo.radius[e]);

			if ((e == lInfo.cur) && (lBlink > 0) && (lBlink < 40) && ((lBlink % 6) > 2))
			{
				float r,g,b,rad;
				r = (float)lBlink / 40;
				g = (float)lBlink / 40;
				b = (float)lBlink / 40;
				rad = lInfo.radius[e];
				G_SetConstantLight(&l->edict->s.constantLight,&r, &g, &b, &rad);
			}
			
		}
	}
}

void liteUpdateSel()
{

	if (lInfo.active[lInfo.cur] == 0)
	{
		gi.cvar_set("rnet_lite_selposx"," ");
		gi.cvar_set("rnet_lite_selposy"," ");
		gi.cvar_set("rnet_lite_selposz"," ");

		gi.cvar_set("rnet_lite_red","1");
		gi.cvar_set("rnet_lite_green","1");
		gi.cvar_set("rnet_lite_blue","1");
		gi.cvar_set("rnet_lite_radius","400");
	
		gi.cvar_set("rnet_lite_sellightname"," ");
	

	} else
	{


	gi.cvar_set("rnet_lite_selposx",va("%.2f",lInfo.pos[lInfo.cur][0]));
	gi.cvar_set("rnet_lite_selposy",va("%.2f",lInfo.pos[lInfo.cur][1]));
	gi.cvar_set("rnet_lite_selposz",va("%.2f",lInfo.pos[lInfo.cur][2]));

	gi.cvar_set("rnet_lite_red",va("%.2f",lInfo.col[lInfo.cur][0]));
	gi.cvar_set("rnet_lite_green",va("%.2f",lInfo.col[lInfo.cur][1]));
	gi.cvar_set("rnet_lite_blue",va("%.2f",lInfo.col[lInfo.cur][2]));
	gi.cvar_set("rnet_lite_radius",va("%.2f",lInfo.radius[lInfo.cur]));

	gi.cvar_set("rnet_lite_sellightname",va("%s",lInfo.name[lInfo.cur]));
	}
}

void liteUpdatevals()
{
	if (lInfo.active[lInfo.cur] == 0) return;
	
	cvar_t *x,*y,*z,*r,*g,*b,*name,*radius;

	x = gi.cvar("rnet_lite_selposx","",0);
	y = gi.cvar("rnet_lite_selposy","",0);
	z = gi.cvar("rnet_lite_selposz","",0);
	r = gi.cvar("rnet_lite_red","",0);
	g = gi.cvar("rnet_lite_green","",0);
	b = gi.cvar("rnet_lite_blue","",0);
	radius = gi.cvar("rnet_lite_radius","",0);
	name = gi.cvar("rnet_lite_sellightname","",0);

	lInfo.pos[lInfo.cur][0] = x->value;
	lInfo.pos[lInfo.cur][1] = y->value;
	lInfo.pos[lInfo.cur][2] = z->value;

	lInfo.col[lInfo.cur][0] = r->value;
	lInfo.col[lInfo.cur][1] = g->value;
	lInfo.col[lInfo.cur][2] = b->value;

	lInfo.radius[lInfo.cur] = radius->value;

	strcpy(lInfo.name[lInfo.cur],name->string);
}

void liteSel(int v)
{
	if (lInfo.num < 2) return;

	lInfo.cur = lInfo.cur + v;
	while(lInfo.active[lInfo.cur] == 0)
	{
		lInfo.cur = lInfo.cur + v;
		if (lInfo.cur < 0) lInfo.cur = lInfo.cur + MAX_LITES;
		if (lInfo.cur >= MAX_LITES) lInfo.cur = lInfo.cur - MAX_LITES;
	}

	liteUpdateSel();
}

void liteSetpos()
{
	if (lInfo.active[lInfo.cur] == 0) return;

	gentity_t * edict;
	Entity * cent = NULL, *ent;
	int num;

	for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
	{
		level.next_edict = edict->next;
		ent = edict->entity;
		if (ent->client != NULL) 
		{
			cent = ent;
		}
	}

	if ( cent )
		{
		lInfo.pos[lInfo.cur][0] = cent->origin.x;
		lInfo.pos[lInfo.cur][1] = cent->origin.y;
		lInfo.pos[lInfo.cur][2] = cent->origin.z + cent->client->ps.viewheight;
		}

	liteUpdateSel();



}

void liteRemove()
{
	if (lInfo.active[lInfo.cur] == 0) return;

	Entity * l = G_GetEntity(lInfo.liteNum[lInfo.cur]);

	delete l;

	lInfo.num --;

	lInfo.active[lInfo.cur] = 0;

	for (int h = MAX_LITES - 1; h >= 0; h-- )
	{
		if (lInfo.active[h] == 1)
		{
			lInfo.cur = h;
		}
	}

	liteUpdateSel();
}

void liteCreate()
{
	// find a free slot...

	int slot = -1;
	for (int e = MAX_LITES-1; e >= 0; e--)
	{
		if (lInfo.active[e] == 0)
		{
			slot = e;
		}
	}

	if (slot == -1) return;

	lInfo.num ++;

	// find out where the client is...

	gentity_t * edict;
	Entity * cent = NULL, *ent;
	int num;

	for( edict = active_edicts.next, num = 0; edict != &active_edicts; edict = level.next_edict, num++ )
	{
		level.next_edict = edict->next;
		ent = edict->entity;
		if (ent->client != NULL) 
		{
			cent = ent;
		}
	}

	if ( !cent )
		return;

	// create new entity...

	Entity * l = new Entity();

	l->setModel("models/light_model.tik");

	lInfo.pos[slot][0] = cent->origin.x;
	lInfo.pos[slot][1] = cent->origin.y;
	lInfo.pos[slot][2] = cent->origin.z + cent->client->ps.viewheight;
 
	lInfo.col[slot][0] = 1;
	lInfo.col[slot][1] = 1;
	lInfo.col[slot][2] = 1;

	lInfo.radius[slot] = 400;

	lInfo.liteNum[slot] = l->entnum;
	lInfo.active[slot] = 1;
	lInfo.cur = slot;

	sprintf(lInfo.name[slot],"light%i",slot);

	liteUpdateSel();

}

void liteWrite()
{
	// write to a script file...
	cvar_t * name;
	name = gi.cvar("rnet_lite_script","",0);

	FILE * fout = fopen(name->string,"wt");

	if (fout == NULL) return;

	fprintf(fout,"void LightingThread();\n");

	fprintf(fout,"void main()\n");
	fprintf(fout,"{\n");
	fprintf(fout,"   LightingThread();\n");
	fprintf(fout,"}\n");
	fprintf(fout,"void LightingThread()\n");


	fprintf(fout,"{\n");
	
	for (int r= 0; r < MAX_LITES; r++)
	{
		if (lInfo.active[r] == 1)
		{
			fprintf(fout,"   spawn (\"light_model\",\"targetname\",\"%s\",\"origin\",\"%.2f %.2f %.2f\");\n",lInfo.name[r],lInfo.pos[r][0],lInfo.pos[r][1],lInfo.pos[r][2]);
			fprintf(fout,"   $%s.lightRed(%.2f);\n",lInfo.name[r], lInfo.col[r][0]);
			fprintf(fout,"   $%s.lightGreen(%.2f);\n",lInfo.name[r], lInfo.col[r][1]);
			fprintf(fout,"   $%s.lightBlue(%.2f);\n",lInfo.name[r], lInfo.col[r][2]);
			fprintf(fout,"   $%s.lightRadius(%.2f);\n",lInfo.name[r], lInfo.radius[r]);
			fprintf(fout,"   $%s.lightOn();\n",lInfo.name[r]);
			fprintf(fout,"\n");
		}
	}

	fprintf(fout,"}\n");

	fclose(fout);
}


void liteNew()
{
	for (int g = 0; g < MAX_LITES; g++)
	{
		if (lInfo.active[g] == 1)
		{
			Entity * l = G_GetEntity(lInfo.liteNum[g]);
			delete l;

			lInfo.active[g] = 0;
		}
	}
	memset(&lInfo,0,sizeof(liteInfo_t));


	lInfo.cur = 0;


	liteUpdateSel();

}

void liteLoad()
{
	cvar_t * name;
	name = gi.cvar("rnet_lite_setup","",0);

	FILE * fin = fopen(name->string,"rb");

	if (fin == NULL) return;

	liteNew();
	fread(&lInfo,sizeof(liteInfo_t),1,fin);

	fclose(fin);
	for (int e = 0; e < MAX_LITES; e++)
	{
		if (lInfo.active[e] == 1)
		{
			Entity * l = new Entity();

			l->setModel("models/light_model.tik");

			lInfo.liteNum[e] = l->entnum;
		}
	}


	liteUpdateSel();
}


void liteSave()
{

	if (lInfo.num == 0) return;

	cvar_t * name;
	name = gi.cvar("rnet_lite_setup","",0);

	FILE * fout = fopen(name->string,"wb");

	if (fout == NULL) return;

	fwrite(&lInfo,sizeof(liteInfo_t),1,fout);

	fclose(fout);

}