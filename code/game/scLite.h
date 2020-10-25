void liteUpdateLights();

void liteCreate();

void liteUpdatevals();

void liteSel(int v);

void liteSetpos();

void liteRemove();

void liteLoad();

void liteSave();

void liteNew();

void liteWrite();

void liteReveal();

#define MAX_LITES 256

typedef struct
{
	int active[MAX_LITES];
	vec3_t pos[MAX_LITES];
	//entityState_t info[MAX_LITES];
	vec3_t col[MAX_LITES];
	int liteNum[MAX_LITES];
	float radius[MAX_LITES];
	char name[MAX_LITES][256];

	int cur;
	int num;
} liteInfo_t;
