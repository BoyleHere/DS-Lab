
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define NUM_STACKS 3

struct Stack
{
    int top;
    int items[MAX_SIZE];
};

void initialize(struct Stack stacks[], int stackSizes[])
{
    for (int i = 0; i < NUM_STACKS; i++)
    {
        stacks[i].top = -1;
    }
    stackSizes[0] = MAX_SIZE / 3;
    stackSizes[1] = MAX_SIZE / 3;
    stackSizes[2] = MAX_SIZE / 3;
}

int isEmpty(struct Stack stack)
{
    return stack.top == -1;
}

int isFull(struct Stack stack, int stackSize)
{
    return stack.top == stackSize - 1;
}

void push(struct Stack stacks[], int stackSizes[], int stackNum, int item)
{
    if (isFull(stacks[stackNum], stackSizes[stackNum]))
    {
        printf("Stack %d is full. Cannot push %d.\n", stackNum, item);
        return;
    }
    stacks[stackNum].items[++stacks[stackNum].top] = item;
}

int pop(struct Stack stacks[], int stackSizes[], int stackNum)
{
    if (isEmpty(stacks[stackNum]))
    {
        printf("Stack %d is empty. Cannot pop.\n", stackNum);
        return -1;
    }
    return stacks[stackNum].items[stacks[stackNum].top--];
}

int main()
{
    struct Stack stacks[NUM_STACKS];
    int stackSizes[NUM_STACKS];

    initialize(stacks, stackSizes);

    push(stacks, stackSizes, 0, 1);
    push(stacks, stackSizes, 1, 11);
    push(stacks, stackSizes, 2, 21);
    push(stacks, stackSizes, 0, 2);
    push(stacks, stackSizes, 1, 12);
    push(stacks, stackSizes, 2, 22);

    printf("Popped from Stack 0: %d\n", pop(stacks, stackSizes, 0));
    printf("Popped from Stack 1: %d\n", pop(stacks, stackSizes, 1));
    printf("Popped from Stack 2: %d\n", pop(stacks, stackSizes, 2));
    printf("Popped from Stack 0: %d\n", pop(stacks, stackSizes, 0));

    return 0;
}
