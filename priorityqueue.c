#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    int key;
    int priority;
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
                if (rear == MAX - 1) {
                    printf("Queue overflow\n");
                } else {
                    printf("Enter an integer key to insert: ");
                    scanf("%d", &x.key);
                    printf("Enter the priority of the element: ");
                    scanf("%d", &x.priority);
                    insert(x);
                }
                break;

            case 2:
                if (front == -1) {
                    printf("Queue underflow\n");
                } else {
                    x = delet();
                    printf("Deleted element is %d with priority %d\n", x.key, x.priority);
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
    if (front == -1) {
        front = 0;
    }
    int i = rear;
    while (i >= front && queue[i].priority > x.priority) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = x;
    rear++;
}

element delet() {
    element deletedElement = queue[front];
    if (front == rear) {
        front = rear = -1;  // Reset queue if it becomes empty
    } else {
        front++;
    }
    return deletedElement;
}

void display() {
    for (int i = front; i <= rear; i++) {
        printf("Key: %d, Priority: %d\n", queue[i].key, queue[i].priority);
    }
}
