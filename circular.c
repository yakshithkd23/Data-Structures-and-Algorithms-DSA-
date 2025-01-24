#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int key;
} element;

element queue[MAX];
int front = -1, rear = -1;

void insert(element x);
element delet();
void display();

int main() {
    element x;
    int choice;

    do {
        printf("Enter a choice:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((rear + 1) % MAX == front) {
                    printf("Queue overflow\n");
                } else {
                    printf("Enter an integer key to insert: ");
                    scanf("%d", &x.key);
                    insert(x);
                }
                break;

            case 2:
                if (front == -1) {
                    printf("Queue underflow\n");
                } else {
                    x = delet();
                    printf("Deleted element is %d\n", x.key);
                }
                break;

            case 3:
                if (front == -1) {
                    printf("Queue is empty\n");
                } else {
                    display();
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

void insert(element x) {
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

element delet() {
    element temp = queue[front];

    // If queue becomes empty after deletion
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return temp;
}

void display() {
    for (int i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", queue[i].key);
    }
    printf("%d\n", queue[rear].key);
}
