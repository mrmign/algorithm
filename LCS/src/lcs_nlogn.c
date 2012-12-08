/*
 * lcs_nlogn.c
 *
 *  Created on: Dec 8, 2012
 *      Author: arming
 */
#include <stdio.h>
#include "lcs_nlogn.h"

/*int binary_search(int a, int b, int k)

{
	int mid;
	while (a < b)
		if (k > last[mid = (a + b) >> 1])
			a = mid + 1;
		else
			b = mid;
	return a;
}

int lis_length(int *s)
{
	int a = 0, b = 0,k;
	int i;
	for(i = 1;i<=LENGTH;i++)
	{
		if(last[k = binary_search(a,b,s[i])]>=s[i])
			last[k] = s[i];
		else
			last[b++] = s[i];
	}
	printf("cnt:%d\n", b);
	return b;
}*/
int lis_length(int *s)
{
	int n = LENGTH;
	int l = 0;
	last[0] = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		int p = 0;
		int r = l;
		while (p <= r)
		{
			int m = (p + r) >> 1;
			if (last[m] < s[i])
				p = m + 1;
			else
				r = m - 1;
		}
		last[p] = s[i];
		if (p > l)
			l = p;
	}
	printf("cnt:%d\n", l);
	return l;
}

/*int lis_length(int *a)
 {
 return 0;
 }*/
void print_lis(int *a, int len)
{
	int i;
	for (i = 1; i <= len; i++)
	{
		printf("%d\n", last[i]);
	}
}
