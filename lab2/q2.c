/* Write a program in C to find GCD of two numbers using recursion. 
Read all pair of numbers from a file and store the result in a separate file. 
Note# Source file name and destination file name taken from command line arguments. 
The source file must contain at least 20 pairs of numbers. */

#include <stdio.h>
#include <time.h>

int gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return gcd(num2, num1 % num2);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        printf("Error in opening the source file!\n");
        return 1;
    }

    FILE *destination_file = fopen(argv[2], "w");
    if (destination_file == NULL) {
        printf("Error in opening the destination file!\n");
        fclose(source_file);
        return 1;
    }

    int num1, num2;
    int count = 0;

    clock_t start, stop;
    start = clock();
    while (fscanf(source_file, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        fprintf(destination_file, "GCD of %d and %d is: %d\n", num1, num2, result);
        count++;
    }
    stop = clock();
    fclose(source_file);
    fclose(destination_file);

    if (count < 20) {
        printf("The source file must contain at least 20 pairs of numbers.\n");
        return 1;
    }

    printf("GCD of pairs calculated and stored in the destination file.\n");
    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC; 
    printf("\nTime taken: %.6f seconds\n", time_taken);
    return 0;
}
