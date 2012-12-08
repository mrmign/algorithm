#include "ShellSort.h"

void shell_sort(float a[], int n)
{
    int i,j,h;
    float temp;
    for (h = 1; h <=(n-1)/9; h = 3*h +1)
    	;
    for (; h > 0; h /= 3)
        for (i = h; i < n; i++)
        {
            j = i;
            temp = a[i];
            while (j >= h && temp < a[j-h])
            {
                a[j] = a[j-h];
                j -= h;
            }
            a[j] = temp;
        }
}
