#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail = NULL;

struct node * addNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

struct node* addFirst(struct node *head,int data){ 
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
    
}


void LinkedList()
{
    struct node *ptr = head;

    while (ptr != NULL)
    {

        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{   int n;
    printf("how many element ypu want: ");
    scanf("%d",&n);
    int x;
    printf("enter element : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        addNode(x);   
    }
    
    LinkedList();
    printf("\n\n");
    return 0;
}