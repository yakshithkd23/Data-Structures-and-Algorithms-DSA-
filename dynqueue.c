#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element;

element *queue = NULL;  // Pointer to dynamically allocate memory for the queue
int front = -1, rear = -1;
int max_size = 0;

void insert(element x);
element delet();
void display();
void resize_queue();

int main() {
    element x;
    int choice;

    printf("Enter the initial size of the queue: ");
    scanf("%d", &max_size);

    queue = (element *)malloc(max_size * sizeof(element));  // Allocate initial memory

    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    do {
        printf("\nEnter a choice:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer key to insert: ");
                scanf("%d", &x.key);
                insert(x);
                break;

            case 2:
                if (front == -1 || front > rear) {
                    printf("Queue underflow\n");
                } else {
                    x = delet();
                    printf("Deleted element is %d\n", x.key);
                }
                break;

            case 3:
                if (front == -1 || front > rear) {
                    printf("Queue is empty\n");
                } else {
                    display();
                }
                break;

            case 4:
                free(queue);  // Free the allocated memory before exiting
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice >= 1 && choice <= 4);

    return 0;
}

void insert(element x) {
    if (rear == max_size - 1) {
        resize_queue();  // Resize the queue if it is full
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = x;
}

element delet() {
    element deleted = queue[front];
    front++;

    if (front > rear) {
        // Reset queue when empty
        front = -1;
        rear = -1;
    }

    return deleted;
}

void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i].key);
    }
    printf("\n");
}

void resize_queue() {
    max_size *= 2;  // Double the size of the queue
    queue = (element *)realloc(queue, max_size * sizeof(element));

    if (queue == NULL) {
        printf("Memory allocation failed during resizing!\n");
        exit(-1);
    }

    printf("Queue resized to %d elements.\n", max_size);
}
