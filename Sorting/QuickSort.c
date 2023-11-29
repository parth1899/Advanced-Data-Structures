#include <stdio.h>  

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int a[], int start, int end)  
{  
    int pivot = a[low]; // pivot element  
    int i = low + 1;
    int j = high;
  
    do{
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }while(i < j);
    swap(&a[low], &a[j]);
    return (i + 1);  
}  
 
void quick(int a[], int low, int high)  
{  
    if (low < high)  
    {  
        int p = partition(a, low, high); //p is the partitioning index  
        quick(a, low, p - 1);  
        quick(a, p + 1, high);  
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
