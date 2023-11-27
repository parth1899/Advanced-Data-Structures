#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct stack
{
    struct node* data;
    struct stack *next;
};

struct stack *top =NULL;

void push(struct node *T)
{
    struct stack *newstack;
    newstack = (struct stack*)malloc(sizeof(struct stack));  
    newstack->data=T;
    newstack ->next=NULL;
    newstack->next=top;
    top = newstack;
}

struct node * pop()
{
    struct stack *temp;
    temp = top;
    struct node * val = temp->data;
    top = top->next;
    free(temp);
    temp = NULL;
    return val;
}

int emptystack()
{
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

struct node * Top()
{
    struct stack *temp;
    temp = top;
    struct node *TOP = temp->data;
    return TOP;
}

struct node* create (struct node *root, int key)
{
    struct node *temp, *p, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = key;
    temp ->left = temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    p = root;
    while (p!=NULL)
    {
        q = p;
        if (key < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p -> right;
        }
        
    }
    if (q->data < key)
    {
        q ->right = temp;
    }
    else
    {
        q->left=temp;
    }
    return root;
}

void preorder(struct node*root)
{
    printf("\nPreorder: ");
    struct node * T = root;
    while (T!=NULL)
    {
        printf("%d ",T->data);
        push(T);
        T=T->left;
    }
    while (emptystack()==1)
    {
        T=pop();
        T=T->right;
        while (T!=NULL)
        {
            printf("%d ",T->data);
            push(T);
            T=T->left;
        }
    }
    printf("\n");
}

void postorder(struct node *root)
{
    printf("Postorder: ");
    struct node*prev;
    struct node* del;
    struct node* T = root;
    do
    {
        while (T!=NULL)
        {
            push(T);
            T=T->left;
        }
        while (T == NULL &&  emptystack()==1)
        {
            T=Top();
            if (T->right == NULL || T->right == prev)
            {
                printf("%d ", T->data);
                prev=T;
                del = pop();
                free(del);
                T = NULL;
            }
            else
            {
                T=T->right;
            }
        }
    } while (emptystack()==1);
    
}


void inorder(struct node*root)
{
    printf("Inorder: ");
    struct node* T = root;
    while (T!=NULL)
    {
        push(T);
        T=T->left;
    }
    while (emptystack()==1)
    {
        T=pop();
        printf("%d ",T->data);
        T=T->right;
        while (T!=NULL)
        {
            push(T);
            T=T->left;
        }  
    }
    printf("\n");
}

void main()
{
    root = create(root,10);
    root = create(root,15);
    root = create(root,7);
    root = create(root,9);
    root = create(root,4);
    root = create(root,36);
    root = create(root,48);
    root = create(root,67);
    root = create(root,50);
    root = create(root,17);
    root = create(root,18);
    root = create(root,19);
    root = create(root,25);
    preorder(root);
    inorder(root);
    postorder(root);
}
