//maxheapify and build maxheap
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int n;
int arr[MAX];
int size[MAX];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left<n && arr[left]>arr[largest])
        largest = left;
    if (right<n && arr[right]>arr[largest])
        largest = right;
    
    if (largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(largest);
    }
}

void buildHeap(){
    int last_non_leaf_node = (n/2)-1;
    for (int i=last_non_leaf_node; i>=0; i--)
        heapify(i);
}

void print(){
    printf("\nArray: ");
    for(int i=0; i<n; i++)
        printf("%d  ", arr[i]);
}

int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    printf("\nThe input array is: ");
    print();
    buildHeap(arr);
    printf("\nArray representation of Max-Heap");
    print();
return 0;
}