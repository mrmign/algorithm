#include "BMgr.h"
static node *head = NULL, *tail = NULL;
/*
 The prototype for this function is FixPage(Page_id, protection)
 and it returns a frame_id. The file and access manager will call
 this page with the page_id that is in the record_id of the record.
 The function looks to see if the page is in the buffer already and
 returns the corresponding frame_id if it is.  If the page is not
 resident in the buffer yet, it selects a victim page, if needed,
 and loads in the requested page.
 */
int FixPage(int page_id, int type)
{
	FUNCTION;
//	printf("%d:%d\n", type, page_id);
	int frm_id = Hash(page_id);
//	printf("frame---%d\n", frm_id);
	BCB *p, *q;
	p = ptof[frm_id];
	q = p;
	while (p)
	{
		if (p->page_id == page_id)
		{
			// p->stime = Time();
			++hitCount;
			SortLRU(page_id);
			type == 0 ? DoNothing() : SetDirty(p->frame_id);
			return p->frame_id;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	//if the requested page doesn't exsit, it need to be loaded.
	++IOCount;
	// there are free buffers
	if (usedBuf < DEFBUFSIZE)
	{
		ReadPage(page_id, usedBuf);

		ftop[usedBuf] = page_id;

		// struct BCB bcb = (struct BCB)malloc(sizeof(struct BCB));
		// bcb.page_id = page_id;
		// bcb.frame_id = usedBuf;
		// bcb.ftime = Time();

		// if(q)
		// 	q->next = &bcb;
		// else
		// 	ptof[frm_id] = &bcb;
		// insert the new page to the tail of LRU list 
		AddBCB(page_id, usedBuf);

		InsertToLRUList(page_id, usedBuf);

		type == 0 ? DoNothing() : SetDirty(usedBuf);
		int f_id = usedBuf;
		usedBuf++;
		return f_id;
	}
	else // all the buffers are full, we need choose one to replace it.
	{
		struct node *pn = head;
		head = head->next;
		int p_id = pn->page_id;
		// load data to this frame
		int fr_id = pn->frame_id;
		free(pn);

		WriteDirty(fr_id);
		RemoveBCB(NULL, p_id);

		ReadPage(page_id, fr_id);
		ftop[fr_id] = page_id;
		AddBCB(page_id, fr_id);
		InsertToLRUList(page_id, fr_id);
		type == 0 ? DoNothing() : SetDirty(fr_id);

		return fr_id;

	}

}

/*
 The prototype for this function is FixNewPage() and it returns a page_id
 and a frame_id.  This function is used when a new page is needed on an insert,
 index split, or object creation.  The page_id is returned in order to assign to
 the record_id and metadata.  This function will find an empty page that the File
 and Access Manager can use to store some data.
 */
//NewPage FixNewPage()
//{
//
//}
/*
 The prototype for this function is UnfixPage(page_id) and it returns
 a frame_id.  This function is the compliment to a FixPage or FixNewPage call.
 This function decrements the fix count on the frame.  If the count reduces to
 zero, then the latch on the page is removed and the frame can be removed if selected.
 The page_id is translated to a frame_id and it may be unlatched so that
 it can be chosen as a victim page if the count on the page has been reduced to zero.
 */
int UnfixPage(int page_id)
{
	return 0;
}

/*
 NumFreeFrames function looks at the buffer and returns the number of buffer pages
 that are free and able to be used.  This is especially useful for the N-way sort
 for the query processor.  The prototype for the function looks like NumFreeFrames()
 and returns an integer from 0 to BUFFERSIZE-1(1023).
 */
int NumFreeFrames()
{
	return 0;
}

// Internal Functions
/*
 SelectVictim function selects a frame to replace.
 If the dirty bit of the selected frame is set then
 the page needs to be written on to the disk.
 */
int SelectVictim()
{
	/*BCB *p, *q;
	 int min_time = 0;
	 int i;
	 for(i = 0; i < DEFBUFSIZE; i++)
	 {

	 p = ptof[i];
	 min_time = p->
	 }*/
	return 0;
}
/*
 Hash function takes the page_id as the parameter
 and  returns the frame id.
 */
int Hash(int page_id)
{
	return page_id % DEFBUFSIZE;
}

/*
 RemoveBCB function removes the Buffer Control Block
 for the page_id from the array.  This is only called
 if the SelectVictim()  function needs to replace a frame.
 */
void RemoveBCB(BCB * ptr, int page_id)
{
	FUNCTION;
	int frame_id = Hash(page_id);
	BCB *p, *q = NULL;
	p = ptof[frame_id];
//	q = p;
	while (p->page_id != page_id)
	{
		q = p;
		p = p->next;
	}
	if (q)
	{
		q->next = p->next;

	}
	else
	{
		ptof[frame_id] = p->next;
	}
	free(p);
}

/*
 RemoveLRUEle function removes the LRU element from the list.
 */
void RemoveLRUEle(int frid)
{

}

/*
 SetDirty function sets the dirty bit for the frame_id.
 This dirty bit is used to know whether or not to write out the frame.
 A frame must be written if the contents have been modified in any way.
 This includes any directory pages and data pages.  If the bit is 1,
 it will be written.  If this bit is zero, it will not be written.
 */
void SetDirty(int frame_id)
{
	FUNCTION;
	int page_id = ftop[frame_id];
	BCB *p = ptof[Hash(page_id)];
	while (p && p->page_id != page_id)
		p = p->next;
	p->dirty = 1;
}

/*
 UnsetDirty function assigns the dirty_bit for the corresponding
 frame_id to zero.  The main reason to call this function is when
 the setDirty() function has been called but the page is actually
 part of a temporary relation.  In this case, the page will not actually
 need to be written, because it will not want to be saved
 */
void UnsetDirty(int frame_id)
{

}

/*
 WriteDirtys function must be called when the system is shut down.
 The purpose of the function is to write out any pages that are still in
 the buffer that may need to be written.  It will only write pages out to
 the file if the dirty_bit is one.
 */
void WriteDirtys()
{
	FUNCTION;
	int i;
	BCB *p;
	for (i = 0; i < DEFBUFSIZE; ++i)
	{
		p = ptof[i];
		while (p)
		{
			if (p->dirty)
			{
				++IOCount;
				WritePage(p->frame_id, buf[p->frame_id]);
			}
			p = p->next;
		}
	}
}

/* 
 writeDirty: write one page that is replaced and dirty_bit is 1
 */
void WriteDirty(int frame_id)
{
	FUNCTION;
	int page_id = ftop[frame_id];
	BCB *p;
	p = ptof[Hash(page_id)];
	while (p && p->page_id != page_id)
	{
		p = p->next;
	}
	if (p->dirty)
	{
		++IOCount;
		WritePage(frame_id, buf[frame_id]);
	}
}
/*
 PrintFrame function prints out the contents of the frame described by the frame_id.
 */
void PrintFrame(int frame_id)
{

}

int Time()
{
	struct timeval tm;
	gettimeofday(&tm, NULL);
	return tm.tv_sec;
}

void InsertToLRUList(int page_id, int frame_id)
{
	FUNCTION;
	struct node *pnode = (node *) malloc(sizeof(node));
	pnode->page_id = page_id;
	pnode->next = NULL;
	pnode->frame_id = frame_id;
	if (!head)
	{
		head = tail = pnode;
	}
	else
	{
		tail->next = pnode;
		tail = pnode;
	}

}

void SortLRU(int page_id)
{
	FUNCTION;
	struct node *p, *q = NULL;
//	q = head;
	p = head;
	int i = 0;
	while (p->page_id != page_id)
	{
		q = p;
		p = p->next;
//		printf("%d\n", i++);
	}
//	FUNCTION;
	if (q)
	{
		if (p->next)
		{
			q->next = p->next;
			tail->next = p;
			tail = p;
			tail->next = NULL;
		}

	}
	else // the first is the one to be read
	{
		if (head->next)
		{
			head = head->next;
			tail->next = p;
			tail = p;
			tail->next = NULL;
		}
	}

}

void AddBCB(int page_id, int frame_id)
{
	FUNCTION;
	BCB *bcb = (BCB *) malloc(sizeof(BCB));
	bcb->page_id = page_id;
	bcb->frame_id = frame_id;
	bcb->next = NULL;
	BCB *p, *q = NULL;
	int page_hash = Hash(page_id);
	p = ptof[page_hash];
//	q = p;
	while (p)
	{
		q = p;
		p = p->next;
	}
	if (!q)
//		p = bcb;
		ptof[page_hash] = bcb;
	else
		q->next = bcb;
}

void DoNothing()
{

}
