/* Write a program in C to convert the first ‘n’ decimal numbers of a disc
file to binary using recursion. Store the binary value in a separate disc file. 
Note# Read the value of ‘n’, source file name and destination file name from command line
arguments. Display the decimal numbers and their equivalent binary numbers from the output
file */

#include <stdio.h>
#include <stdlib.h>

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
        printf("Error in input\n", argv[0]);
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

    for (int i = 0; i < n; i++) {
        binary[i] = toBinary(arr[i]);
    }

    printf("\nThe Array with corresponding binary values is: ");
    printArr(binary, n);

    // Write the binary values to the destination file
    FILE *destination_file = fopen(argv[3], "w");
    if (destination_file == NULL) {
        printf("Error in opening the destination file!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(destination_file, "%d\n", binary[i]);
    }
    fclose(destination_file);

    return 0;
}
