#include "QuickSort.h"

int partition(float a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    int j;
    float temp;
    for (j = p; j < r; j++ )
    	if (a[j] <= x)
        {
            i = i + 1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;

}

void quick_sort(float a[], int p, int r)
{
    if(p < r)
    {
        int q = partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}
