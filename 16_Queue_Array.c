#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr)
{
    if (ptr->r == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Cannot insert queue is full");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

int Dequeue(struct queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    Enqueue(&q, 12);
    Enqueue(&q, 45);

    printf("deleted in element: %d \n ", Dequeue(&q));
    printf("deleted in element: %d \n ", Dequeue(&q));
    if (isEmpty(&q))
    {
        printf("Queue is Empty");
    }
    if (isFull(&q))
    {
        printf("Queue is Full");
    }
}