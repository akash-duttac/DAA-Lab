#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int value;
    int weight;
    float ratio;
} Item;

int compare(const void *a, const void *b) 
{
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return itemB->ratio - itemA->ratio;
}

void knapsackGreedy(Item items[], int n, int capacity) 
{
    qsort(items, n, sizeof(Item), compare);
    int currentWeight = 0;
    int totalValue = 0;

    for (int i = 0; i < n; ++i) 
    {
        if (currentWeight + items[i].weight <= capacity) 
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else 
        {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }
    printf("Maximum Value that can be Obtained : %d\n", totalValue);
}

int main() 
{
    int n, capacity;                                // Number of Items
    printf("Enter no. of items: ");
    scanf("%d", &n);
    printf("Enter capacity: ");
    scanf("%d", &capacity);

    Item items[n];
    printf("Enter value & corresponding weights\n");
    for(int i=0; i<n; i++){
        printf("Item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    

    for (int i = 0; i < n; ++i) 
    {
        items[i].ratio = (float)(items[i].value / items[i].weight);
    }
    knapsackGreedy(items, n, capacity);
    return 0;
}