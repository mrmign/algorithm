#ifndef RANDOMDECIMAL_H_INCLUDED
#define RANDOMDECIMAL_H_INCLUDED

#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#define NUMBER 100000
void produceRandom()
{
    time_t t;
    srand((unsigned) time(NULL));
    int i = 0;
    FILE * fout = fopen("100000_2.txt","w");
    for (i = 0; i < NUMBER-1; i ++)
//        printf("%f \n",rand()/(double)RAND_MAX);
        fprintf(fout,"%f\n",rand()/(double)RAND_MAX);
    fprintf(fout,"%f",rand()/(double)RAND_MAX);
}


#endif // RANDOMDECIMAL_H_INCLUDED

/*产生一定范围随机数的通用表示公式
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。*/
