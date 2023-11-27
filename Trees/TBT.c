#include <stdio.h>
#include <stdlib.h>

struct TBTnode
{
    struct TBTnode *left, *right;
    int lbit, rbit;
    int data;
};

struct TBTnode *head;

struct TBTnode* insert(struct TBTnode *head, int key)
{
    struct TBTnode *temp, *root, *q;
    temp = (struct TBTnode*)malloc(sizeof(struct TBTnode));
    temp -> rbit = temp -> lbit=0;
    temp -> data = key;

    if(head->left==head){
         temp->right=head;
         temp->left=head;
         head->left=temp;
         return head;
     }

     root=head->left;
     while(1)
        {
         q=root;
         if(key < root->data && root->lbit==1){
            root=root->left;
         }
         else if(key>root->data && root->rbit==1){
             root=root->right;
         }
         else{
             break;
         }
     }

     if(key > q->data){
        temp->right=q->right;
        temp->left = q;
        q->right = temp;
        q->rbit = 1;
     }
     else{
        temp->left = q->left;
        temp->right = q;
        q->left = temp;
        q->lbit = 1;
    }
    return head;
}

void inorder(struct TBTnode*head){
    printf("\nInorder: ");
    if(head->left==head){
      printf("Tree is empty");
      return;
    }
    struct TBTnode*ptr;
    ptr=head->left;
    do{
      while(ptr->lbit!=0){
          ptr=ptr->left;
      }
      printf("%d->",ptr->data);
      while(ptr->rbit==0){
          ptr=ptr->right;
          if(ptr==head){
              return;
          }
          printf("%d->",ptr->data);
      }
      ptr=ptr->right;
    }while(ptr!=head);
}

void preorder(struct TBTnode*head){

    printf("Preorder: ");
    if(head->left==head){
        printf("Tree is empty");
        return;
    }
    struct TBTnode*ptr;
    ptr=head->left;
    do{
      while(ptr->lbit!=0){
          printf("%d->",ptr->data);
          ptr=ptr->left;
      }
      printf("%d->",ptr->data);
      while(ptr->rbit==0){
          ptr=ptr->right;
          if(ptr==head){
              return;
          }
      }
      ptr=ptr->right;
    }while(ptr!=head);
    }

/*
void postorder(struct TBTnode* head) {

    printf("Postorder: ");
    if (head->left == head) {
        printf("Tree is empty\n");
        return;
    }

    struct TBTnode* ptr = head->left;
    struct TBTnode* prev = NULL;

    while (ptr->lbit == 1) {
        ptr = ptr->left;
    }

    while (ptr != head) {
        while (ptr->rbit == 0 && ptr->right != head) {
            printf("%d->", ptr->data);
            prev = ptr;
            ptr = ptr->right;
        }

        if (ptr->right == head) {
            prev = ptr;
            ptr = ptr->right;
        } else {
            prev=ptr;//new
            ptr = ptr->right;
            while (ptr->lbit == 1) {
                prev=ptr; //new
                ptr = ptr->left;
            }
        }
    }
    printf("\n");
}*/


void main()
{
    int val,key,choice;
    struct TBTnode*head=(struct TBTnode*)malloc(sizeof(struct TBTnode));
    head->lbit=head->rbit=1;
    head->left=head;
    head->right=head;
    do {
    printf(" 1.Insert\n 2.Preorder\n 3.Inorder\n 4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value:");
        scanf("%d",&key);
        head=insert(head,key);
        break;

        case 2:
        preorder(head);
        printf("\n");
        break;

        case 3:
        inorder(head);
        printf("\n");
        break;
        /*
        case 4:
        postorder(head);
        printf("\n");
        break;*/

        default:
        printf("Enter your choice again\n");
        break;
    }
    }while(choice!=4);
}
