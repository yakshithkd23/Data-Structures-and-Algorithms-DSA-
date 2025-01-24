#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

char expn[MAX];  
int stack[MAX];  
int top = -1;  
void push(int item);
int pop();
char get_token(char *symbol, int *n);
int eval();
int main() {
    int result;
    printf("Enter the postfix expression: ");
    scanf("%s", expn); 

    result = eval(); 
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    }
    else{
    stack[++top] = item;
    }
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    }
    else{
    return stack[top--];
    }
}
char get_token(char *symbol, int *n) {
    *symbol = expn[*n];
    *n = *n + 1;
    return *symbol;
}

int eval() {
    char symbol;
    int n = 0, x, op1, op2;
    symbol = get_token(&symbol, &n);

    while (symbol != '\0') {
        if (symbol >= '0' && symbol <= '9') {  // If symbol is an operand (number)
            x = symbol - '0';  // Convert character to integer
            push(x);
        } else {  
            op2 = pop();
            op1 = pop();
            switch (symbol) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
                default:
                    printf("Invalid operator encountered: %c\n", symbol);
                
            }
        }
        
        symbol = get_token(&symbol, &n);
    }

    if (top == 0) {
        return pop();  // Return the final result
    } else {
        printf("Invalid Expression\n");
}
}
