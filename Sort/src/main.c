#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "RandomDecimal.h"
#include "definition.h"
#include "InsertSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "BucketSort.h"
#define NUM 100000
//#define file "1000.txt"

//#define NUM 10000
//#define file "10000.txt"

//#define NUM 100000
//#define file "100000.txt"

int main()
{
//	produce random number
//	produceRandom();

	FILE *in = fopen("100000_2.txt", "r");
	Item a[NUM];
	int i = 0;
	for (i = 0; i < NUM; i++)
		fscanf(in, "%f", &a[i]);

//    calculate runtime
	struct timeval s_time, e_time;
	gettimeofday(&s_time, NULL);

//    insert_sort(a,NUM);
    bubble_sort(a,NUM);
//    quick_sort(a,0,NUM - 1);
//    shell_sort(a,NUM);
//	merge_sort(a, 0, NUM - 1);
//	bucket_sort(a,NUM);

	gettimeofday(&e_time, NULL);
	float runtime = (e_time.tv_sec - s_time.tv_sec) * 1000000 + e_time.tv_usec
			- s_time.tv_usec;
    printf("runtime: %f \n",runtime/1000000);

//	for (i = 0; i < NUM; i++)
//		printf("%f\n", a[i]);

	return 0;
}

