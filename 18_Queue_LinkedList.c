#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void Enqueue(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Queue is full....!! ");
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (f == NULL)
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            r = ptr;
        }
    }
}
int Dequeue()
{
    struct Node *ptr;
    int val = -1;

    if (f == NULL)
    {
        printf("Queue is Empty!! ");
    }
    else
    {
        ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void display(struct Node *ptr)
{
    printf("\n Element in Queue: \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    Enqueue(12);
    Enqueue(90);
    Enqueue(67);
    Enqueue(46);
    display(f);
    Dequeue();
    display(f);
}