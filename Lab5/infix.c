#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    stack.top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top != -1 && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top == -1 || stack.data[stack.top] != '(') {
                printf("Invalid Expression\n");
                exit(1);
            }
            pop(&stack); // Discard '('
        } else if (isOperator(infix[i])) {
            while (stack.top != -1 && stack.data[stack.top] != '(' && precedence(infix[i]) <= precedence(stack.data[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        } else {
            printf("Invalid Expression\n");
            exit(1);
        }
    }

    while (stack.top != -1 && stack.data[stack.top] != '(') {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
