#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20
typedef struct
{
    int arr[MAX];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

bool isFull(Stack *s)
{
    return s->top == MAX - 1;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflown...\n");
        return -1;
    }
    int popped = s->arr[s->top];
    s->top--;
    printf("popped %d from the stack\n", popped);
    return popped;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack is overflown\n");
        return;
    }
    s->arr[++s->top] = value;
    printf("pushed %d on Stack\n", value);
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    initialize(s);
    push(s, 3);
    printf("top element: %d\n", peek(s));
    push(s, 5);
    printf("top element: %d\n", peek(s));
    while (!isEmpty(s))
    {
        printf("Top element: %d\n", peek(s));
        printf("Popped Element: %d\n", pop(s));
    }
    free(s);
    return 0;
}