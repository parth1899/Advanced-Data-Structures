#include <stdio.h>  

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&a[i], &a[j]);  
        }  
    }  
    swap(&a[i+1], &a[end]);
    return (i + 1);  
}  
 
void quick(int a[], int start, int end)  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  

int main()  
{  
    int a[] = { 24, 9, 29, 14, 19, 27 };  
    int n = sizeof(a) / sizeof(a[0]);  

    quick(a, 0, n - 1);  
    printf("\nAfter sorting array elements are - \n");    
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]); 
      
    return 0;  
}  
