#ifndef DSMGR_H_
#define DSMGR_H_

#include <stdio.h>
#include "global.h"

	int OpenFile(char* filename);
	int CloseFile();
	bFrame ReadPage(int page_id, int frame_id);
	int WritePage(int frame_id, bFrame frm);
	int Seek(int offset);
	FILE * GetFile();
	void IncNumPages();
	int GetNumPages();
	void SetUse(int page_id, int use_bit);
	int GetUse(int page_id);

// FILE *currFile;
// int numPages;
// int pages[MAXPAGES];

#endif