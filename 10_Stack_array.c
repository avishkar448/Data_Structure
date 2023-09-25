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

int main()
{

    struct stack *s;
      s=(struct stack*)malloc(sizeof(struct stack));

    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

//manually 
    s->arr[0]=23;
    s->top++;
    
    if (isEmpty(s))
    {
        printf("stack is empty!!");
    }
    else
    {
        printf("stack is not empty!");
    }

        
}