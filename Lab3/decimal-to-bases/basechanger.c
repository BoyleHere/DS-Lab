#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to push a value onto the stack
void push(int stack[], int *top, int value) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++(*top)] = value;
}

// Function to pop a value from the stack
int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
        return -1; // Return a special value to indicate an error
    }
    return stack[(*top)--];
}

// Function to convert decimal to any base using a stack
void decimalToBase(int decimal, int base) {
    int stack[MAX_SIZE];
    int top = -1;

    while (decimal > 0) {
        int remainder = decimal % base;
        push(stack, &top, remainder);
        decimal /= base;
    }

    printf("Number in base %d: ", base);
    while (top != -1) {
        int digit = pop(stack, &top);
        printf("%d", digit);
    }
    printf("\n");
}

int main() {
    int decimal, base;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Enter the desired base: ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Invalid base. Please choose a base between 2 and 16.\n");
        return 1; // Return an error code
    }

    decimalToBase(decimal, base);

    return 0;
}
