#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = item;
    printf("Inserted %d at front\n", item);
}

void insertRear(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;  
    } else if (rear == MAX - 1) {
        rear = 0;
    } else { 
        rear++;
    }
    deque[rear] = item;
    printf("Inserted %d at rear\n", item);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) { // Deque is now empty
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) { // Deque is now empty
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\nDeque Operations:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the item to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}