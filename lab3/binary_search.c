#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int binary_search(int c[], int size, int target){
    int left = 0;
    int right = size-1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(c[mid]==target)
            return mid;
        else if (c[mid]<target)
            left = mid+1;
        else
            right = mid-1;
    }

    return 0;
}
void insertion(int arr[], int size){
    for (int i=1; i<size; i++){
            int key = arr[i];
            int j = i-1;
            while (j>=0 && key<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
}
int main()
{
    int size[10], arr[MAX];
    clock_t start, stop;
    double exec, proc_time[10];
    srand(time(NULL));
    printf("Enter 10 array sizes: ");
    for (int i=0; i<10; i++)
        scanf("%d", &size[i]);
    
    //adding elements to the 10 arrays
    for (int i=0; i<10; i++){
        for (int j=0; j<size[i]; j++){
            arr[j]=rand();
        }
        insertion(arr,size[i]);
        start=clock();
        int key;
        printf("Array-%d\tEnter element to search for?: ",i);
        scanf("%d", &key);
        if(!binary_search(arr,size,key))
            printf("\nElement not found!");
        else
            printf("\nElement at index %d", binary_search(arr,size,key));
        stop=clock();
        exec=(double)(stop-start);
        proc_time[i] = exec/CLOCKS_PER_SEC;
    }
    for (int i=0; i<10; i++)
    printf("Size: %d\t\tTime taken: %f\n", size[i], proc_time[i]);
return 0;
}