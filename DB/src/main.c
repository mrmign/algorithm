#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
// #include "global.h"
#include "DSMgr.h"
#include "BMgr.h"

int main()
{
	FILE *trace = fopen("data-5w-50w-zipf.txt", "r");
	int type, page_id;
	int i = 500000;
	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	while (i--)
	{
		fscanf(trace, "%d,%d", &type, &page_id);
		FixPage(page_id, type);
//		printf("IO: %d  hit: %d\n", IOCount, hitCount);
	}

	WriteDirtys();
	fclose(trace);
	CloseFile();

	gettimeofday(&end_time, NULL);
	float totalTime = ((end_time.tv_sec - start_time.tv_sec)*1000000 + end_time.tv_usec - start_time.tv_usec)/1000.0;
	printf("totalTime: %fms, total IOs: %d, hitRatio:%f",totalTime, IOCount, (float)hitCount/IOCount);
	// FILE *out = fopen("1.txt", "r+");
	// char a[50] = {'a','b','c'};

	// fseek(out, 3, SEEK_SET);
	// fwrite(a, sizeof(char), 3, out);
	// fread(buf[0].field, sizeof(char), 50, out);

	// fseek(out, 20, SEEK_SET);
	// fwrite(a, sizeof(char), strlen(a), out);
	// for (int i = 0; i < 50; ++i)
	// {
	// 	printf("%c\n", a[i]);
	// }
	// printf("%d\n", strlen(a));

	// fclose(out);
	// printf("%s\n", buf[0].field);
	// struct timeval tm;
	// gettimeofday(&tm, NULL);
	// printf("%lu\n", tm.tv_sec*1000000+tm.tv_usec);
	// printf("%d\n", tm.tv_sec);

	return 0;
}
