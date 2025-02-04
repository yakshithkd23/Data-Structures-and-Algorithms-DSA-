#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int key;
} element;

element heap[MAX];
int heapSize = 0; //here it is same as stack but instead of heap there they mentioned that heapsize and also instead of -1 here 0

void insertMaxHeap(element x);
void insertMinHeap(element x);
element extractMax();
element extractMin();
void displayHeap();
void swap(element *a, element *b);

int main() {
    element x;
    int choice, heapType;

    printf("Choose Heap Type:\n1. Max Heap\n2. Min Heap\n");
    scanf("%d", &heapType);

    do {
        printf("\nEnter a choice:\n");
        printf("1. Insert\n2. Extract Root\n3. Display Heap\n4.exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (heapSize == MAX) {
                    printf("Heap overflow\n");
                    break;
                }
                printf("Enter an element to insert into the heap: ");
                scanf("%d", &x.key);
                
                if (heapType == 1)
                    insertMaxHeap(x);
                else
                    insertMinHeap(x);
                break;

            case 2:
                if (heapSize == 0) {
                    printf("Heap underflow\n");
                    break;
                }
                if (heapType == 1)
                    x = extractMax();
                else
                    x = extractMin();
                
                printf("Extracted element: %d\n", x.key);
                break;

            case 3:
                if (heapSize == 0) {
                    printf("Heap is empty\n");
                } else {
                    displayHeap();
                }
                break;

        
            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice >= 1 && choice <= 4);

    return 0;
}

// Swap function
void swap(element *a, element *b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into Max Heap
void insertMaxHeap(element x) {
    heap[heapSize] = x;
    int index = heapSize;
    heapSize++;

    // Heapify Up (Bubble Up)
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].key < heap[index].key) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        } 
    }
}

// Insert into Min Heap
void insertMinHeap(element x) {
    heap[heapSize] = x;
    int index = heapSize;
    heapSize++;

    // Heapify Up (Bubble Up)
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].key > heap[index].key) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Extract Max (Remove root from Max Heap)
element extractMax() {
    element maxValue = heap[0];
    heap[0] = heap[--heapSize];

    int index = 0;
    while (index < heapSize) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heapSize && heap[left].key > heap[largest].key)
            largest = left;
        if (right < heapSize && heap[right].key > heap[largest].key)
            largest = right;
        if (largest != index) {
            swap(&heap[index], &heap[largest]);
            index = largest;
        } else {
            break;
        }  
    }
    return maxValue;
}

// Extract Min (Remove root from Min Heap)
element extractMin() {
    element minValue = heap[0];
    heap[0] = heap[--heapSize];

    int index = 0;
    while (index < heapSize) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heapSize && heap[left].key < heap[smallest].key)
            smallest = left;
        if (right < heapSize && heap[right].key < heap[smallest].key)
            smallest = right;
        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
    return minValue;
}

// Display Heap
void displayHeap() {
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i].key);
    printf("\n");
}
