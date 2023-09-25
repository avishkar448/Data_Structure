#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main()
{
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(5);

    /*
     // Root
     p = (struct Node *)malloc(sizeof(struct Node));
     p->left = NULL;
     p->right = NULL;
     p->data = 34;

     // first
     p1 = (struct Node *)malloc(sizeof(struct Node));
     p1->left = NULL;
     p1->right = NULL;
     p1->data = 12;

     // second
     p2 = (struct Node *)malloc(sizeof(struct Node));
     p2->left = NULL;
     p2->right = NULL;
     p2->data = 89;

     // linkinf the node
     p->left = p1;
     p->right = p2;
     return 0;
     */
}