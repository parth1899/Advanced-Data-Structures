#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = * a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int index)
{
  int largest = index;
  int leftChild = 2*index + 1;
  int rightChild = 2*index + 2;

  if(leftChild < n && arr[leftChild] > arr[largest])
  {
    largest = leftChild;
  }

  if (rightChild < n && arr[rightChild] > arr[largest])
  {
    largest = rightChild;
  }

  if (largest != index)
  {
    swap(&arr[index], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n)
{
  for (int i = n/2 -1; i >= 0; i--)
  {
    heapify(arr, n, i); //for building max heap
  }

  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]); //start iteration from last position
    heapify(arr, i, 0); //the highest element will again go back to the root 
    }
}

void main()
{  
  int arr[] = {48, 10, 23, 43, 28, 26, 1};
  int n = sizeof(arr)/sizeof(int);  

  heapsort(arr, n);

  printf("\nSorted Array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

} 
