#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedList(struct Node *ptr)
{

    while (ptr != NULL)
    {

        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}




int main()
{

    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 43;
    head->next = first;

    first->data = 100;
    first->next = second;

    second->data = 123;
    second->next = third;

    third->data = 786;
    third->next = NULL;

    LinkedList(head);
    return 0;
}