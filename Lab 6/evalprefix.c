#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = item;
    }
}

int pop() {
    int item;

    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

int evaluate_prefix(char prefix[]) {
    int i, operand1, operand2, result;
    char symbol;

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        symbol = prefix[i];

        if (isdigit(symbol)) {
            push(symbol - '0');
        } else {
            operand1 = pop();
            operand2 = pop();

            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid Expression\n");
                    return -1;
            }

            push(result);
        }
    }

    result = pop();

    if (top >= 0) {
        printf("Invalid Expression\n");
        return -1;
    }

    return result;
}

int main() {
    char prefix[MAX];

    printf("Enter Prefix expression : ");
    gets(prefix);

    int result = evaluate_prefix(prefix);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}
