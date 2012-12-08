/*
 * lcs.h
 *
 *  Created on: Dec 7, 2012
 *      Author: arming
 */

#ifndef LCS_H_
#define LCS_H_
/*
 * dir
 *
 * |0 |1|
 * |-1|*|
 */
typedef struct st
{
	int cnt; // count
	int dir; //driction
} data_t;

void lcs_length(int *, int *);
void print_lcs(int *, int, int);

#define SIZE 1000

data_t c[SIZE + 1][SIZE + 1];

#endif /* LCS_H_ */
