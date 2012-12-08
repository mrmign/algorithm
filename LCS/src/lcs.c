/*
 * lcs.c
 *
 *  Created on: Dec 7, 2012
 *      Author: arming
 */
#include "lcs.h"
void lcs_length(int *x, int *y)
{
	int i, j;
	for (i = 1; i <= SIZE; ++i)
		for (j = 1; j <= SIZE; j++)
		{
			if (x[i] == y[j])
			{
				c[i][j].cnt = c[i - 1][j - 1].cnt + 1;
				c[i][j].dir = 0;
			}
			else if (c[i - 1][j].cnt >= c[i][j - 1].cnt)
			{
				c[i][j].cnt = c[i - 1][j].cnt;
				c[i][j].dir = 1;
			}
			else
			{
				c[i][j].cnt = c[i][j - 1].cnt;
				c[i][j].dir = -1;
			}
		}
}

void print_lcs(int *a, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (c[i][j].dir == 0)
	{
		print_lcs(a, i - 1, j - 1);
		printf("%d\n", a[i]);
	}
	else if (c[i][j].dir == 1)
		print_lcs(a, i - 1, j);
	else
	{
		print_lcs(a, i, j - 1);
	}
}
