#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Check if the character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to push item to the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = item;
}

// Function to pop item from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

// Convert postfix expression to infix
void postfixToInfix(char postfix[]) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    char buffer[MAX_SIZE * 2]; // Buffer for constructing the infix expression
    int i = 0;
    char ch, op1, op2;

    while ((ch = postfix[i++]) != '\0') {
        if (isOperand(ch)) {
            push(stack, ch);
        } else {
            op2 = pop(stack);
            op1 = pop(stack);
            // Construct the infix expression in a buffer
            sprintf(buffer, "(%c%c%c)", op1, ch, op2);
            // Push the constructed infix expression onto the stack
            for (int j = 0; buffer[j] != '\0'; j++) {
                push(stack, buffer[j]);
            }
        }
    }
    printf("Infix Expression: %s\n", stack->items);
    free(stack);
}

int main() {
    char postfixExpression[MAX_SIZE];
    printf("Enter the postfix expression: ");
    fgets(postfixExpression, MAX_SIZE, stdin);
    postfixToInfix(postfixExpression);
    return 0;
}
