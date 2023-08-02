/* WAP to find out the second smallest and second largest elements stored in an array of n integers */
#include <stdio.h>
#include <stdlib.h>
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void sort(int arr[], int n){
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (arr[i] > arr[j+1])
                swap(&arr[i],&arr[j]);
}
int main()
{
    int n;
    printf("Enter size of an array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("\nInput array: ");
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    sort(arr,n);
    printf("\n2nd largest element: %d", arr[n-2]);
    printf("\n2nd smallest element: %d", arr[1]);
return 0;
}