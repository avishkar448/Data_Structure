#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

int Push(struct stack *ptr, int val)
{

    if (isFull(ptr))
    {
        printf("Stack is full ");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 1;
    }
    else
    {
        int v = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return v;
    }
}

int ParenthesisMatching(char *exp)
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            Pop(s);
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "(2+3))+(3*8)";

    if (ParenthesisMatching(exp))
    {
        printf("Parenthesis Matching !!");
    }
    else
    {
        printf("Parenthesis is not Matching !!");
    }
}
