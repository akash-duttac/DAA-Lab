#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    char data;
    int frequency;
    struct Node *left, *right;
};
struct MinHeap{
    int size, capacity;
    struct Node** array;
};
struct Node* newNode(char data, int frequency){
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}
struct MinHeap* createMinHeap(int capacity){
    struct MinHeap* minHeap = 
}
int main()
{
return 0;
}