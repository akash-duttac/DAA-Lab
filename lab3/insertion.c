#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
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
    int size[MAX], arr[MAX];
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
        insertion(arr,size[i]);
        stop=clock();
        exec=(double)(stop-start);
        proc_time = exec/CLOCKS_PER_SEC;
        printf("Size: %d\t\tTime taken: %f", size[i], proc_time);
    }
return 0;
}