/* Write a program in C to convert the first ‘n’ decimal numbers of a disc
file to binary using recursion. Store the binary value in a separate disc file. 
Note# Read the value of ‘n’, source file name and destination file name from command line
arguments. Display the decimal numbers and their equivalent binary numbers from the output
file */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int toBinary(int num) {
    if (num == 0) {
        return 0;
    } else {
        return num % 2 + 10 * toBinary(num / 2);
    }
}

void printArr(int c[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d  ", c[i]);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error in input\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int arr[n], binary[n];

    FILE *source_file = fopen(argv[2], "r");
    if (source_file == NULL) {
        printf("Error in opening the source file!\n");
        return 1;
    }

    printf("Reading integers from the txt file\n");
    for (int i = 0; i < n; i++) {
        if (fscanf(source_file, "%d", &arr[i]) != 1) {
            printf("Error in reading the file\n");
            fclose(source_file);
            return 1;
        }
    }
    fclose(source_file);

    printf("The array obtained is: ");
    printArr(arr, n);

    clock_t start, stop;
    start = clock();
    for (int i = 0; i < n; i++) {
        binary[i] = toBinary(arr[i]);
    }
    stop = clock();

    printf("\nThe Array with corresponding binary values is: ");
    printArr(binary, n);

    FILE *destination_file = fopen(argv[3], "w");
    if (destination_file == NULL) {
        printf("Error in opening the destination file!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(destination_file, "%d\n", binary[i]);
    }
    fclose(destination_file);
    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC; 
    printf("\nTime taken: %.6f seconds\n", time_taken);
    return 0;
}
