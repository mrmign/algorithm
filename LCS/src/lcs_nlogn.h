/*
 * lcs_nlogn.h
 *
 *  Created on: Dec 8, 2012
 *      Author: arming
 */

#ifndef LCS_NLOGN_H_
#define LCS_NLOGN_H_

#define LENGTH 1000

int lis_length(int *);
void print_lis(int *,int length);

int last[LENGTH];

#endif /* LCS_NLOGN_H_ */
