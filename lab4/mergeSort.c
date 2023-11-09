#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int size[MAX], arr[MAX], merge[MAX];
void merging(int low, int mid, int high){
    int a = low;
    int b = mid+1;
    int i;
    for (i = low; a<=mid && b<=high; i++){
    	//merge 
    	if (arr[a] <= arr[b])
    		merge[i] = arr[a++];
    	else
    		merge[i] = arr[b++];
    }
     /*while (l1<=mid)
            mergeArr[i++] = arr[l1++];
     while (l2<=high)
            mergeArr[i++] = arr[l2++];
        for (i=low; i<=high; i++)
            arr[i] = mergeArr[i];*/
    while (a<=mid)
    	merge[i++] = arr[a++];
    while (b<=high)
    	merge[i++] = arr[b++];
    	
   	//reassign to original array
    for (int i=low; i<=high; i++)
    	arr[i] = merge[i];
}
void sort(int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        sort(low,mid);
        sort(mid+1,high);
        merging(low,mid,high);
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
        sort(0,size[i]-1);
        stop=clock();
        exec=(double)(stop-start);
        proc_time = exec/CLOCKS_PER_SEC;
        printf("n= %d, Time taken: %f\n", size[i], proc_time);
    }
return 0;
}