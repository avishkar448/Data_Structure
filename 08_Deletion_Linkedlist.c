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
struct Node* deleteFirst(struct Node*head){ 
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}


// Case 2
struct Node* deleteAtIndex(struct Node* head,int index){

    struct Node*p=head;
    struct Node*q=p->next;
    for(int i=1;i<=index-1;i++){ 
        p=p->next;
        q=q->next;
    } 

    p->next=q->next;
    free(q);
    return head;
}

// case 3
struct Node*deleteAtEnd(struct Node* head){ 
    struct Node*p=head;
    struct Node*q=p->next;

    while(q->next!=NULL){
        p=p->next;
        q=q->next;
     }

     p->next=q->next;
     free(q);
     return head;

}

// case 4
struct Node* deleteAtValue(struct Node*head,int value){ 
    struct Node*p=head;
    struct Node*q=p->next;

    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next; 

    }
    if(q->data==value){
        p->next=q->next;
        free(q);

     }
     else{ 
        printf("\nvalue is not in linked list!!\n");
     }
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
   // head = deleteFirst(head);
  //  head = deleteAtIndex(head,1);
  //  head = deleteAtEnd(head);
    head = deleteAtValue(head,30);
    display(head);

    return 0;
}