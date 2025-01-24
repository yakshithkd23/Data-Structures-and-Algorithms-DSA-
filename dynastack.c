#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element;

element *stack = NULL;  // Pointer to dynamically allocate memory for the stack
int top = -1;
int max_size = 0;

void push(element x);
element pop();
element peek();
void display();
void resize_stack();

int main() {
    element x;
    int choice;

    printf("Enter the initial size of the stack: ");
    scanf("%d", &max_size);

    stack = (element *)malloc(max_size * sizeof(element));  // Allocate initial memory for the stack

    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    do {
        printf("\nEnter a choice:\n");
        printf("1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to push to stack: ");
                scanf("%d", &x.key);
                push(x);
                break;

            case 2:
                if (top == -1) {
                    printf("Stack underflow\n");
                } else {
                    x = pop();
                    printf("Popped element is %d\n", x.key);
                }
                break;

            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    x = peek();
                    printf("Top of the stack is %d\n", x.key);
                }
                break;

            case 4:
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    display();
                }
                break;

            case 5:
                free(stack);  // Free the dynamically allocated memory
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice >= 1 && choice <= 5);

    return 0;
}

void push(element x) {
    if (top == max_size - 1) {
        resize_stack();  // Resize the stack if it is full
    }

    stack[++top] = x;
}

element pop() {
    return stack[top--];
}

element peek() {
    return stack[top];
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i].key);
    }
}

void resize_stack() {
    max_size *= 2;  // Double the size of the stack
    stack = (element *)realloc(stack, max_size * sizeof(element));

    if (stack == NULL) {
        printf("Memory allocation failed during resizing!\n");
        exit(-1);
    }

    printf("Stack resized to %d elements.\n", max_size);
}
