#include "InsertSort.h"

void insert_sort(Item a[], int n)
{
    int i, j;
    float temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i-1;
        while(j >= 0 && temp < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;

    }
}

