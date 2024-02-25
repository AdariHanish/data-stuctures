#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return -1;
}

// Function to check if the character is an operand
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

// Convert infix expression to postfix
void infixToPostfix(char infix[]) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    char postfix[MAX_SIZE];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i]; ++i) {
        ch = infix[i];

        if (isOperand(ch)) {
            postfix[j] = ch;
            j++;
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (stack->top != -1 && stack->items[stack->top] != '(') {
                postfix[j] = pop(stack);
                j++;
            }
            if (stack->top != -1 && stack->items[stack->top] != '(') {
                printf("Invalid expression\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (stack->top != -1 && precedence(ch) <= precedence(stack->items[stack->top])) {
                postfix[j] = pop(stack);
                j++;
            }
            push(stack, ch);
        }
    }

    while (stack->top != -1) {
        postfix[j] = pop(stack);
        j++;
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
    free(stack);
}

int main() {
    char infixExpression[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infixExpression, MAX_SIZE, stdin);
    infixToPostfix(infixExpression);
    return 0;
}