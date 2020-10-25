void npNoclip(int v);

void npSpeed(int v);

void npPersp(int v);

void npCam(int v);

void npUpdateangles();

void npDropcamera();

void npUpdateCamera();

void npDropmodel();

void npSelmodel(int v);

void npChangemodel();

void npWritescript();

void npPickup();

void npRemoveLight();

extern Event EV_SetLight;
extern Event EV_LightOn;
extern Event EV_LightRed;
extern Event EV_LightRadius;
extern Event EV_LightGreen;

typedef struct
{
	int dropmodelnext;
	int noclip;
	int speed;
	int persp;
	int camfix;
	int dist;
	double yaw;
	double pitch;
	double camFov[256];
	double fv;

	double camX,camY,camZ;

	double camP, camYAW, camR;

	vec3_t camPlace[256];
	vec3_t camAng[256];
	int cams;
	vec3_t modPlace[256];
	int modNum[256];
	int mods;

	int curMod;

	entityState_t modInfo[256];

} scNodePlace_t;