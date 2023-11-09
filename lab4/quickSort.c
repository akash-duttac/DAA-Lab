#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int size[MAX], arr[MAX];
int partition(int low, int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
void quick_sort(int low, int high){
    if (low < high){
            int partitionIndex = partition(low,high);
            quick_sort(low, partitionIndex-1);
            quick_sort(partitionIndex+1, high);
    }
}
int main()
{
    
    clock_t start, stop;
    double exec, proc_time;
    srand(time(NULL));
    printf("Enter 10 array sizes: ");
    for (int i=0; i<10; i++)
        scanf("%d", &size[i]);
    
    //adding elements to the 10 arrays
    for (int i=0; i<10; i++){
        start = clock();
        for (int j=0; j<size[i]; j++){
            arr[j]=rand();
        }
        quick_sort(0,size[i]-1);
        stop=clock();
        exec=(double)(stop-start);
        proc_time = exec/CLOCKS_PER_SEC;
        printf("n = %d, Time taken: %f\n", size[i], proc_time);
    }
return 0;
}