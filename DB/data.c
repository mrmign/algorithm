#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#ifndef BUFFERSIZE
#define BUFFERSIZE 4096
#endif

int main1(int argc, char const *argv[])
{
	int pages = 50000;
	time_t t;
    srand((unsigned) time(NULL));
    FILE *data = fopen("data.dbf","w");
    int all = BUFFERSIZE * pages;
    int i;
    for(i = 0; i < all; i++)
    	fprintf(data, "%c", (char)(40 + rand() % 87));
	return 0;
}
