#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each node in the Huffman tree
struct Node {
    char data;
    int frequency;
    struct Node *left, *right;
};

// Define a structure for the min-heap
struct MinHeap {
    int size;
    int capacity;
    struct Node** array;
};

// Function to create a new node
struct Node* newNode(char data, int frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new min heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

// Function to swap two nodes in the min heap
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify the min heap
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the size of the min heap is 1
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the minimum node from the min heap
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the min heap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Build the Huffman tree and return the root node
struct Node* buildHuffmanTree(char data[], int frequency[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], frequency[i]);
    }
    minHeap->size = size;

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Print Huffman codes from the root of the Huffman Tree
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Huffman coding function
void huffmanCodes(char data[], int frequency[], int size) {
    struct Node* root = buildHuffmanTree(data, frequency, size);
    int arr[size], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
}

int main() {
    /*char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};*/

    char data[100];
    int frequency[100];
    int n;
    printf("Enter no. of characters: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        printf("Enter character: ");
        fflush(stdin);
        scanf("%c", &data[i]);
        printf("Enter frequency: ");
        scanf("%d", &frequency[i]);
    }
    // int size = sizeof(data) / sizeof(data[0]);
    huffmanCodes(data, frequency, n);
    return 0;
}
