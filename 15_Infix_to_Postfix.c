#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *Infix_to_Postfix(char *infix)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (char *)malloc(s->size * (sizeof(char)));
    int i = 0;
    int j = 0;
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(StackTop(s)))
            {
                Push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = Pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = Pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "x-y/z-k*d";
    printf("Infix: %s", infix);
    printf("\nInfix to Postfix : %s", Infix_to_Postfix(infix));
}