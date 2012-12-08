/*
 * BucketSort.c
 *
 *  Created on: Oct 23, 2012
 *      Author: arming
 */

#include "BucketSort.h"
//pNode b[10];
void bucket_sort(Item a[], int n)
{
	int i, j;
	Node *b;
	b = (Node *)malloc(sizeof(Node)*10);
	for (j = 0; j < 10; j++)
	{
		b[j].next = NULL;
		b[j].value = 0;
	}

	for (i = 0; i < n; i++)
	{
		Node *newNode = (Node*) malloc(sizeof(Node));
		newNode->value = a[i];
		newNode->next = NULL;
		insert_node(newNode,b);
	}
	j = 0;
	Node *p;
	for (i = 0; i< 10;i++)
	{
		p = (Node*)b[i].next;
		while(p)
		{
			a[j++] = p->value;
			p = (Node*)p->next;
		}
	}
}

void insert_node(Node *start, Node *b)
{
	Item v = (start->value) * 10;
	int i = (int) v;
	Node *p, *q;
	if (NULL != b[i].next)
	{
		p = (Node*)b[i].next;
//		q = b[i];
		while (p && (p->value) < (start->value))
		{
			q = p;
			p = (Node*)p->next;
		}
		if (NULL == p)
		{
			q->next = start;
		}
		else
		{
			start->next = p;
			b[i].next = start;

		}
	}
	else
	{
		b[i].next = start;
	}

}
