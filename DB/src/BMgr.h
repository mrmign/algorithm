
#ifndef BMGR_H_
#define BMGR_H_

#include <malloc.h>
#include <sys/time.h>
#include "global.h"
#include "DSMgr.h"
  // Interface functions
  int FixPage(int page_id, int type);
//  NewPage FixNewPage();
  int UnfixPage(int page_id);
  int NumFreeFrames();

  // Internal Functions
  int SelectVictim();
  int Hash(int page_id);
  void RemoveBCB(BCB * ptr, int page_id);
  void RemoveLRUEle(int frid);
  void SetDirty(int frame_id);
  void UnsetDirty(int frame_id);
  void WriteDirtys();
  void PrintFrame(int frame_id);

  int Time();
  void InsertToLRUList(int page_id, int frame_id);
  void SortLRU(int page_id);

  void AddBCB(int page_id, int frame_id);

  void WriteDirty(int frame_id);

  void DoNothing();
  // Hash Table
  // int ftop[DEFBUFSIZE];
  // BCB* ptof[DEFBUFSIZE];

#endif
