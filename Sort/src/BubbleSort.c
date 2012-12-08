#include "BubbleSort.h"

void bubble_sort(float a[], int n)
{
    int j;
    float temp;
    int swap = n;
    while (swap)
    {
        int bound = swap;
        swap = 0;
        for (j = 1; j < bound; j++)
        {
            if(a[j] < a[j-1])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                swap = j;
            }
        }
    }

}
