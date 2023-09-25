#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    int a = -1;
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full!! \n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueue element: %d\n", val);
    }
}

int Dequeue(struct circularQueue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue is full!! ");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        val = q->arr[q->r];
    }
    return val;
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    Enqueue(&q, 12);
    Enqueue(&q, 16);
    Enqueue(&q, 17);
    Dequeue(&q);
    Dequeue(&q);
    Enqueue(&q, 100);
    Enqueue(&q, 100);

    if (isEmpty(&q))
    {
        printf("Queue is Empty");
    }
    if (isFull(&q))
    {
        printf("Queue is Full");
    }
}