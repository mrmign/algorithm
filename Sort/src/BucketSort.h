/*
 * BucketSort.h
 *
 *  Created on: Oct 23, 2012
 *      Author: arming
 */

#ifndef BUCKETSORT_H_
#define BUCKETSORT_H_
#include "definition.h"
#include <malloc.h>
typedef struct node
{
	Item value;
	struct Node *next;
} Node, *pNode;

void bucket_sort(Item a[], int n);
void insert_node(Node *start,Node *b);

#endif /* BUCKETSORT_H_ */
