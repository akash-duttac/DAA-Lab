// WAP to create a function to search an element in array using linear search.
// Take arrays of 3 different sizes and calculate the time taken to search an
// element in each case. Compare the time taken by the function o/p format.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printArr(int arr[], int n){
    for (int i=0; i<n; i++)
        printf("%d  ", arr[i]);
}
bool search(int c[], int size, int key){
    for (int i=0; i<size; i++)
        if (c[i]==key)
        return true;
    return false;
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    FILE *file = fopen("file.txt", "r");
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
    int key;
    printf("\nEnter element to search for: ");
    scanf("%d", &key);

    clock_t start = clock();
    if (search(arr,n,key))
        printf("\nElement is present in array");
    else
        printf("\nElement not found in array");
    clock_t stop = clock();

    double time_taken = ((double)(stop-start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %g", time_taken);
return 0;
}