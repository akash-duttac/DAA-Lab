// Knapsack algorithm implementation
#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void sort(int w[], int v[], int n)
{
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++){
            double ratio1 = (double) v[j]/w[j];
            double ratio2 = (double) v[j+1]/w[j+1];
            if (ratio1 < ratio2){
                swap(&v[j], &v[j+1]);
                swap(&w[j], &w[j+1]);
            }
        }
}

double knapsack(int weights[], int values[], int size, int capacity)
{
    sort(weights,values,size);

    double total_value = 0.0;
    int current_weight = 0;

    for (int i=0; i<size; i++){
        if (current_weight + weights[i] <= capacity){
            total_value += values[i];
            current_weight += weights[i];
        } else {
            double fraction = (double) (capacity - current_weight)/weights[i];
            total_value += values[i]*fraction;  
            break;
        }
    }

    return total_value;
}

int main()
{
    int size, capacity;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter capacity: ");
    scanf("%d", &capacity);

    int *weights = (int *)malloc(size*(sizeof(int)));
    int *values = (int *)malloc(size*(sizeof(int)));

    printf("Enter the weight and corresponding values\n");
    for (int i=0; i<size; i++){
        printf("%d=> ",i+1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    double maximum_value = knapsack(weights,values,size,capacity);

    printf("Maximum achievable value: %.2lf", maximum_value);
    
    free(weights);
    free(values);
    return 0;
}