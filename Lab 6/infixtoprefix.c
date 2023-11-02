#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    char item;

    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

int is_operator(char symbol) {
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infix_to_prefix(char infix[], char prefix[]) {
    int i, j = 0;
    char item;
    char x;

    push('(');
    strcat(infix, ")");
    i = 0;

    while (infix[i] != '\0') {
        item = infix[i];

        if (item == '(') {
            push(item);
        } else if (isdigit(item) || isalpha(item)) {
            prefix[j] = item;
            j++;
        } else if (is_operator(item) == 1) {
            x = pop();

            while (is_operator(x) == 1 && precedence(x) >= precedence(item)) {
                prefix[j] = x;
                j++;
                x = pop();
            }

            push(x);
            push(item);
        } else if (item == ')') {
            x = pop();

            while (x != '(') {
                prefix[j] = x;
                j++;
                x = pop();
            }
        } else {
            printf("Invalid Expression\n");
            return;
        }

        i++;
    }

    if (top > 0) {
        printf("Invalid Expression\n");
        return;
    }

    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter Infix expression : ");
    gets(infix);

    infix_to_prefix(infix, prefix);

    printf("Prefix Expression: ");
    puts(prefix);

    return 0;
}
