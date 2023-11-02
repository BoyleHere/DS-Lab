#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char item[]) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        strcpy(stack[top], item);
    }
}

char* pop() {
    char* item;

    if (top < 0) {
        printf("Stack Underflow\n");
        return NULL;
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

char* prefix_to_infix(char prefix[]) {
    int i, operand1_len, operand2_len;
    char operand1[MAX], operand2[MAX], result[MAX], symbol[MAX];

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        symbol[0] = prefix[i];
        symbol[1] = '\0';

        if (isdigit(symbol[0]) || isalpha(symbol[0])) {
            push(symbol);
        } else {
            strcpy(operand1, pop());
            strcpy(operand2, pop());

            operand1_len = strlen(operand1);
            operand2_len = strlen(operand2);

            if (operand1_len > 1) {
                sprintf(operand1, "(%s)", operand1);
            }

            if (operand2_len > 1) {
                sprintf(operand2, "(%s)", operand2);
            }

            sprintf(result, "(%s %s %s)", operand1, symbol, operand2);
            push(result);
        }
    }

    char* final_result = pop();

    if (top >= 0) {
        printf("Invalid Expression\n");
        return NULL;
    }

    return final_result;
}

int main() {
    char prefix[MAX], infix[MAX];

    printf("Enter Prefix expression : ");
    gets(prefix);

    char* result = prefix_to_infix(prefix);

    if (result != NULL) {
        printf("Fully Parenthesized Infix Expression: %s\n", result);
    }

    return 0;
}
