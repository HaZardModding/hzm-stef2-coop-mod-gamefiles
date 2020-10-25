#define MAX_FILMCLIPS 1024

#define SCFILM_DISK 0
#define SCFILM_PAK 1

#define RNET_ENT_NONE 0 // no entitiy in this slot at all
#define RNET_ENT_USED 1 // used previously
#define RNET_ENT_TEMP 2 // used by rnet as a tempentity
#define RNET_ENT_MOD 3 // used previously, now modified...

#define RNET_MAX_SOUNDBUFFER 1024

// should be called by the redemption code every 20th of a second
// to do whatever the RNET code is currently supposed to be doing...

void scUpdate();

// just to handle console commands...
void scProcCommand(const char * p1, const char * p2);

//void SV_Sound( vec3_t *org, int entnum, int channel, const char *sound_name, float volume, float min_dist );
void scAddSound( vec3_t *org, int entnum, int channel, const char *sound_name, float volume, float min_dist ,int ss);

// work out the differences between two chunks of memory, record the changes
int compCompressData(unsigned char * indata, unsigned char * old_indata, unsigned char * outdata, int inDataSize, int outDataSize);

// to decompress the data, we need the original data as well as the changes to apply...
int compDecompressData(unsigned char * indata, unsigned char * outdata, int inDataSize, int outDataSize);

typedef struct
{
	char filename[255];
	double inpoint;
	double outpoint;
	double len; // calculate clip length when it is added to the project
} scRNetClip_t;

typedef struct
{
	scRNetClip_t * clip[MAX_FILMCLIPS];
	int clipnum; // first clip that is displayed in the cliplist window

	double filmTime;
	int filmState;
} scRNetFilm_t;

typedef struct
{
	 vec3_t org;
	 int entnum;
	 int channel;
	 unsigned char name_length;
	 float volume;
	 float min_dist;
	 int ss;
	 char * name;
} scRNetSoundInfo_t;

typedef struct
{
	scRNetSoundInfo_t * sound[RNET_MAX_SOUNDBUFFER];
} scRNetSoundBuffer_t;