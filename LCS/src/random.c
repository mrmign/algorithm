/*
 * random.c
 *
 *  Created on: Dec 6, 2012
 *      Author: arming
 */

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 10000

int main1()
{
	int b[MAXSIZE];
//	int count = 0;

	FILE *fout = fopen("10000.txt", "w");
	int i, w, t;
	for (i = 0; i < MAXSIZE; i++)
	{
		b[i] = i + 1;
	}

	for (i = MAXSIZE - 1; i > 0; i--)
	{
		w = rand() % i;
		t = b[i];
		b[i] = b[w];
		b[w] = t;

	}
	for (i = 0; i < MAXSIZE; i++)
		fprintf(fout, "%d\n", b[i]);
//		printf("%d\n",b[i]);
	return 0;
}
/*srand(time(0));
 //　 srand(time(NULL));
 printf("One hunderd random number from 0 to %d\n\n",MAXSIZE);
 //　printf("Ten random numbers from 0 to 99\n\n");
 for( int i = 0; i < MAXSIZE; i++ )
 {
 b[i] = rand()%MAXSIZE;
 count ++;
 for( int j = 0; j < i; j++)
 {
 if( b[j] == b[i] )
 {
 i--;
 break;
 }
 }
 }
 for( int m = 0; m < MAXSIZE; m++ )
 {
 printf("%d\t" ,b[m]);
 }
 printf("total circle number is: %d\n",count);
 }*/

//int main()
//{
// time_t begin,end;
// begin=clock();
// //begin test code
// test();
// //end test code
// end=clock();
//// cout<<"runtime: "<<double(end-begin)/CLOCKS_PER_SEC<<endl;
// return 0;
//}
