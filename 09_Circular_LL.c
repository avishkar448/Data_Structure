#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *InsertAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct Node *InsertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    head = ptr->next;
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->next != head)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = p->next;
    for (int i = 1; i <= index - 1; i++)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

void display(struct Node *ptr)
{
    struct Node *p = ptr;

    do
    {
        printf("%d\t", p->data);
        p = p->next;
    } while (p != ptr);
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *one = (struct Node *)malloc(sizeof(struct Node));
    struct Node *two = (struct Node *)malloc(sizeof(struct Node));
    struct Node *three = (struct Node *)malloc(sizeof(struct Node));

    head->data = 43;
    head->next = one;

    one->data = 100;
    one->next = two;

    two->data = 123;
    two->next = three;

    three->data = 786;
    three->next = head;
    printf("before:  \n");
    display(head);
    printf("\nAfter:  \n");
    //  head=InsertAtFirst(head,7);
    //  head=InsertAtLast(head,7);
    // head=InsertAtIndex(head,2,12);
    //   head=deleteAtFirst(head);
    //   head=deleteLast(head);
    head = deleteAtIndex(head, 2);
    display(head);
}