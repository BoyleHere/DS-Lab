#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Function to push a character onto the stack
void push(char stack[], int *top, char c) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++(*top)] = c;
}

// Function to pop a character from the stack
char pop(char stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[(*top)--];
}

// Function to check if a given string is a palindrome
bool isPalindrome(const char *str) {
    char stack[MAX_SIZE];
    int top = -1;

    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        push(stack, &top, str[i]);
    }

    for (int i = 0; i < length; i++) {
        char c = pop(stack, &top);
        if (c != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}
