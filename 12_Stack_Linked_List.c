#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

//Empty Function
int isEmpty(struct Node *top)
{

    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Full Function
int isFull(struct Node *top)
{

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    { 
        return 0;
    }
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

//Push
struct Node *push(struct Node *top, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (isFull(top))
    {
        printf("Stack overflow.......!");
    }
    else
    {
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
}
//Pop
int pop(struct Node *top1)
{
    struct Node *ptr;
    if (isEmpty(top1))
    {
        printf("Stack is Empty........!");
    }
    else
    {
        ptr = top1;
        top = (top1)->next;
        int n = ptr->data;
        free(ptr);
        return n;
    }
}
//Peek Function
int Peek(int pos){
     struct Node*ptr=top;
     for(int i=0;(i<pos-1 && ptr!=NULL);i++){ 
        ptr=ptr->next;
     }
     if(ptr!=NULL){ 
        return ptr->data;
     }
     else{ 
        return -1;
     }

}

//stack Top
int StackTop(){ 
    return top->data;
}

//Stack Bottom
int StackBottom(){ 
    struct Node*ptr=top;
    while(ptr->next!=NULL){ 
        ptr=ptr->next;
    }
    return ptr->data;
}

int main()
{

    top = push(top, 89);
    top = push(top, 55);
    top = push(top, 67);
    top = push(top, 43);
    top = push(top, 28);
    top = push(top, 71);
    printf("before:  \n");
    display(top);

    printf("\nafter:  \n");
    int ele = pop(top);

    printf("Element %d pop from stack \n", ele);
    display(top);

    printf("\n\n Element %d \n",Peek(2));
    
    printf("Top Element %d\n",StackTop());
    printf("Bottom Element %d\n",StackBottom());
}