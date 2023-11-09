//maxheapify and build maxheap
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int n;
int arr[MAX];

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

int deleteMax() {
    if (n == 0) {
        printf("\nHeap is empty.\n");
        return -1; // Return a sentinel value to indicate an empty heap
    }

    int max = arr[0]; // Maximum element in the heap
    arr[0] = arr[n - 1]; // Replace the root with the last element
    n--; // Decrease the size of the heap
    heapify(0); // Heapify the root

    return max;
}

void print(){
    printf("\nArray: ");
    for(int i=0; i<n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
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

    printf("\nDeleting elements from Max-Heap:\n");
    while (n > 0) {
        int max = deleteMax();
        if (max != -1) {
            printf("Deleted element: %d\n", max);
            //print();
        }
    }
return 0;
}