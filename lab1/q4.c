/* Write a function named rotate_right with parameters p1 & p2. Create a function exchange
with parameters int a, int b that swaps a & b. The rotate_right funciton will use the exchange
function to shift right p2 elements starting from index p1 by one position.*/

#include <stdio.h>
#include <stdlib.h>
void print_arr(int arr[], int size){
    for (int i=0; i<size; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rotate_right(int p1, int p2, int c[], int size) {
    for (int j=p1+p2-1; j>p1; j--)
        swap(&c[j],&c[j-1]);
}
int main()
{
    int n, p1, p2;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    FILE *file = fopen("file.txt", "r");
    if (file == NULL){
        printf("\nError in opening the file!\n");
        return 1;
    }
    printf("Reading integers from the txt file\n");
    for (int i=0; i<n; i++){
        if(fscanf(file, "%d", &arr[i]) != 1){
            printf("Error in reading the file\n");
            return 1; 
        }
    }
    fclose(file);
    printf("The array obtained is: ");
    print_arr(arr,n);
    printf("\nEnter index: ");
    scanf("%d", &p1);
    printf("Enter no. of elements: ");
    scanf("%d", &p2);
    rotate_right(p1,p2,arr,n);
    printf("\nRotated List: ");
    print_arr(arr,n);
return 0;
}
