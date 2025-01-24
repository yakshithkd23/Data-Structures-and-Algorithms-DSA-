#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                if (rear == MAX - 1) {
                    printf("Queue overflow\n");
                } else {
                    printf("Enter an integer key to insert: ");
                    scanf("%d", &x.key);
                    
                    insert(x);
                }
                break;

            case 2:
                if (front == rear) {
                    printf("Queue underflow\n");
                } else {
                    x = delet();
                    printf("Deleted element is  %d\n", x.key);
                }
                break;

            case 3:
                if (front == rear) {
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
    queue[++rear] = x;
}

element delet() {
    return queue[front++];
}

void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d\n ", queue[i].key);
    }
}
