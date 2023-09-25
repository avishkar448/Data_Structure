#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

void display(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
// case 1
struct Node *InsertFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    head = ptr;

    //  return ptr;
}
// Case 2
struct Node *InsertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// case 3
struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// case 4
struct Node *InsertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *one = (struct Node *)malloc(sizeof(struct Node));
    struct Node *two = (struct Node *)malloc(sizeof(struct Node));
    struct Node *three = (struct Node *)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = one;

    one->data = 30;
    one->next = two;

    two->data = 55;
    two->next = three;

    three->data = 88;
    three->next = NULL;

    printf("Befor: \n");
    display(head);
    printf("\nAfter: \n");
    //  head = InsertFirst(head,90);
    //  head = InsertAtIndex(head,90,2);
    //  head = InsertAtEnd(head,90);
    head = InsertAfter(head, two, 90);
    display(head);

    return 0;
}