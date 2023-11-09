#include <stdio.h>
#include <stdlib.h>

int arr[100000];
int merge[100000];

void showArr(int c[], int size){
    for(int i=0; i<size; i++)
        printf("%d  ",c[i]);
    printf("\n");
}

void merging(int low, int mid, int high){
    int a = low;
    int b = mid+1;
    int i;
    for (i=low; a<=mid && b<=high; i++){
        if (arr[a] <= arr[b])
            merge[i] = arr[a++];
        else
            merge[i] = arr[b++];
    }
    while (a<=mid)
        merge[i++] = arr[a++];
    while (b<=high)
        merge[i++] = arr[b++];

    for (int i=low; i<=high; i++)
        arr[i] = merge[i];
}

void merge_sort(int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merging(low,mid,high);
    }
}
int main()
{
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    
    for (int i=0; i<size; i++)
        arr[i]=rand();
    
    printf("Array:\n");
    showArr(arr,size);
    
    merge_sort(0,size-1);

    printf("Sorted array\n");
    showArr(merge,size);
return 0;
}