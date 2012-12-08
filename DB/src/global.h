#ifndef GLOBAL
#define GLOBAL

#define FRAMESIZE  4096
#define DEFBUFSIZE 1024
struct bFrame
{
	char field[FRAMESIZE];
};

typedef struct bFrame bFrame;
bFrame buf[DEFBUFSIZE];

struct NewPage
{
	int page_id;
	int frame_id;
};

struct BCB
{

	// BCB();
	int page_id;
	int frame_id;
	int latch;
	int count;
	// time of the first recorded access
	int ftime;
	// time of the second recorded access
	int stime;
	int dirty;
	struct BCB * next;

};
typedef struct BCB BCB;
// LRU-2 node
struct node
{
	int page_id;
	// struct BCB *bcb;
	int frame_id;
	struct node *next;
};
typedef struct node node;

// Hash Table
int ftop[DEFBUFSIZE];
BCB* ptof[DEFBUFSIZE];

//the number of used buffer
int usedBuf;
// record I/O times
int IOCount;
// record hit times
int hitCount;

// 
//#define FUNCTION printf("%s\n", __func__)
#define FUNCTION
#endif
