/* WAP to create a function that checks for each element of the array if it
is a multiple of 3 or 5 or both or neither 3 or 5. If it is a multiple of 3, it will
be replace by 3. If it is a multiple of 5, it will be multiplied by 5. If a 
multiple of 15, it will be multiplied by 15, if a multiple of neither 3 nor 5, it will
be replaced by 0 */

#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n){
    for (int i=0; i<n; i++)
        printf("%d  ", arr[i]);
}
void func(int c[], int size){
    for (int i=0; i<size; i++){
        if (c[i]%3 == 0 && c[i]%5==0)
            c[i] *= 15;
        else if (c[i]%3 == 0)
            c[i] = 3;
        else if (c[i]%5 == 0)
            c[i] *= 5;
        else
            c[i] = 0;
    }
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
    func(arr,n);
     printf("\nNew Array: ");
    printArr(arr,n);
return 0;
}