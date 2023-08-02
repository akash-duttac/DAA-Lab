/* WAP to read n integers from a disc file that must contain some duplicate values and store them into
   an array. Perform the following operations on the array.
    (a) Find out the total no. of duplicate elements
    (b) Find out the most repeating element in the array
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    FILE *file = fopen("source.txt", "r");
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
    for (int i=0; i<n; i++)
        printf("%d  ", arr[i]);
    
    // (a) total no. of duplicate elements
    int duplicate_count = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (arr[i] == arr[j]){
                duplicate_count++;
                break;
            }
    printf("\nDuplicate count = %d", duplicate_count);

    // (b) most repeating element in array
    int no_of_repeats = 0;
    int most_repeating_no;
    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=i+1; j<n; j++){
            if (arr[i]==arr[j]){
                count++;
            }
            if (count > no_of_repeats){
                most_repeating_no = arr[i];
                no_of_repeats = count;
            }    
        }
    }
    printf("\nMost repeated element: %d", most_repeating_no);
return 0;
}