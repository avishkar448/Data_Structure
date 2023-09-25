#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{

    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{

    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{

    if (isFull(ptr))
    {
        printf("stack overflow!!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{

    if (isEmpty(ptr))
    {
        printf("stack is empty !! ");
    }
    else
    {
        int v = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return v;
    }
}

int peek(struct stack *ptr, int i)
{

    if (ptr->arr[ptr->top - i + 1] < 0)
    {
        printf("invalid");
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int StackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{

    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 56);
    push(s, 16);
    push(s, 90);
    push(s, 20);
    push(s, 77);
    push(s, 43);

    printf("%d pop form stack\n ", pop(s));

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("the value at index %d is %d\n ", j, peek(s, j));
    }

    printf("\nStack TOP: %d", StackTop(s));
    printf("\nStack BOTTOM: %d ", StackBottom(s));

    return 0;
}