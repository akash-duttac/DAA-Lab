//WAP to create a function and reverse an array. Take arrays of 3 different sizes
//and calculate the time taken to reverse the array in each case. Compare the time
//taken by the function to reverse the arrays of different sizes. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArr(int arr[], int n){
    for (int i=0; i<n; i++)
        printf("%d  ", arr[i]);
}
void reverse(int c[], int size){
    for (int start=0, end=size-1; start<end; start++, end--)
        swap(&c[start],&c[end]);
}
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    FILE *file = fopen("input1.txt", "r");
    if (file == NULL){
        printf("\nError in opening the file!\n");
        return 1;
    }
    
    for (int i=0; i<n; i++){
        if(fscanf(file, "%d", &arr[i]) != 1){
            printf("Error in reading the file\n");
            return 1; 
        }
    }
    fclose(file);
    printf("\nOriginal Array: ");
    printArr(arr,n);

    clock_t start = clock();
    reverse(arr,n);
    clock_t stop = clock();
    printf("\nReversed Array: ");
    printArr(arr,n);

    double time_taken = ((double)(stop-start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.9f", time_taken);
return 0;
}