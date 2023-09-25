#include<stdio.h>
#include<stdlib.h>

struct Node{ 
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){ 
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int isBST(struct Node* root){ 
    static struct Node* prev=NULL;
    if(root!=NULL){ 
        if(!isBST(root->left)){ 
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){ 
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{ 
        return 1;
    }
}

struct Node* Search(struct Node* root,int key){ 
    if(root==NULL){ 
        return NULL;
    }
    if(key==root->data){ 
        return root;
    }
    else if(key<root->data){ 
        return Search(root->left,key);
    }
    else{ 
        return Search(root->right,key);
    }
}

int main(){ 
    struct Node* p=createNode(9);
    struct Node* p1=createNode(4);
    struct Node* p2=createNode(11);
    struct Node* p3=createNode(2);
    struct Node* p4=createNode(7);
    struct Node* p5=createNode(15);
    struct Node* p6=createNode(5);
    struct Node* p7=createNode(8);
    struct Node* p8=createNode(14);

   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   p2->right=p5;
   p4->left=p6; 
   p4->right=p7;
   p5->left=p8;
   
  if(isBST(p)){ 
    printf("This is Binary Search Tree! ");
  }
  else{ 
    printf("This is not a Binary Search Tree! ");
  }
printf("\n");
  struct Node* n=Search(p,90);

  if(n!=NULL){ 
    printf("Found: %d ",n->data);
  }
  else{ 
    printf("Element not Found!!");
  }

}