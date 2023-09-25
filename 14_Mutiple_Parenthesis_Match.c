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

int Matching(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int Multi_ParenthesisMatching(char *exp)
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char poped;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            Push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            poped = Pop(s);
            if (!Matching(poped, exp[i]))
            {
                return 0;
            }
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
    char *exp = "{(2+3)}";

    if (Multi_ParenthesisMatching(exp))
    {
        printf("Parenthesis is Balenced !!");
    }
    else
    {
        printf("Parenthesis is not Balenced !!");
    }
}
