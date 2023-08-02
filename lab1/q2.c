/* Find the prefix sum of an array */
#include <stdio.h>
#include <stdlib.h>
void print(int arr[], int n){
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
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
    print(arr,n);
    int prefix[n];
    prefix[0] = arr[0];
    for (int i=1; i<n; i++)
        prefix[i] = prefix[i-1] + arr[i];
    printf("\nPrefix Sum Array: ");
    print(prefix,n);
return 0;
}