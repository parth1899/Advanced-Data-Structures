#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *right,*left;
int data;
};
struct node *root=NULL;
 typedef struct stack
{
 struct node* data;
 struct stack *next;
}stack;
struct stack *top=NULL;

void push(struct node *T)
{
struct stack *newstack;
newstack=malloc(sizeof(struct stack));
newstack->data=T;
newstack->next=NULL;
newstack->next=top;
top=newstack;
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
 int isempty()
 {
 if(top==NULL)
   return 0;
 else
   return 1;
 }
 struct node *Top()
 {
 struct stack *temp;
 temp=top;
 struct node *Top=temp->data;
 return Top;
 }
  typedef struct queue
  {
      struct node** arr;
      int f,r;
      int size;
      int capacity;
  }queue;

   struct queue* createQueue(int capacity)
    {
     struct  queue *q = ( struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->f= 0;
    q->size = 0;
    q->r = capacity - 1;
    q->arr = ( struct node**)malloc(q->capacity * sizeof( struct node *));
    return q;
}
int isQueueEmpty(queue *queue)
{
    return (queue->size == 0);
}
  int Enqueue(struct queue *q,struct node *root)
  {
      if(root==NULL)
        return ;
      q->arr[q->r++]=root;
  }
  int Dequeue(struct queue *q)
  {
      int a=(q->arr[q->f])->data;
      q->f++;
      return a;
  }


 struct node *insert(struct node *root,int key)
 {
    struct node *temp,*p,*q;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=key;
     temp->right=temp->left=NULL;
     if(root==NULL)
     {
         root=temp;
         return root;
     }
    p=root;
    while(p!=NULL)
   {
    q=p;
     if(key<p->data)
    {
        p=p->left;
    }
    else
    {
       p=p->right;
    }
    }
    if(q->data<key)
    {
        q->right=temp;
    }
    else
    {
        q->left=temp;
    }
    return root;
}
 void Preorder(struct node *root)
{
    printf("\nPreorder:");
    while(root!=NULL)
    {
        printf("%d ",root->data);
        push(root);
        root=root->left;
    }
    while(isempty()==1)
    {
        root=pop();
        root=root->right;
        while(root!=NULL)
       {
        printf("%d ",root->data);
        push(root);
        root=root->left;
       }
    }
    printf("\n");
}
void Inorder(struct node *root)
{
    printf("\nInorder:");
    while(root!=NULL)
    {
        push(root);
        root=root->left;
    }
    while(isempty()==1)
    {
        root=pop();
        printf("%d ",root->data);
        root=root->right;
        while(root!=NULL)
    {
        push(root);
        root=root->left;
    }
    }
    printf("\n");
}
void Postorder(struct node *root)
{
    printf("\nPostorder:");
    struct node *prev;
    do
    {
        while(root!=NULL)
        {
            push(root);
            root=root->left;
        }
        while(root==NULL && isempty()==1)
        {

            root=Top();
            if(root->right==NULL || root->right==prev)
            {
                printf("%d ",root->data);
                prev=root;
                pop();
                root=NULL;
            }
            else
                root=root->right;
        }
    }while(isempty()==1);
    printf("\n");
}

void mirror( struct node* root) {
    if (root == NULL)
        return;
     struct node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear) {
         struct node* current = queue[front++];

        // Swap the left and right children of the current node
         struct node* temp = current->left;
        current->left = current->right;
        current->right = temp;

        // Enqueue left and right children
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}
int height(struct node *root)
{
    if (root == NULL)
        return 0;
     struct node* queue[1000];
    int f = 0, r = 0;
    queue[r++] = root;

    int depth = 0;
    while (f != r) {
        int nodesAtCurrentDepth = r - f;  // Number of nodes at current depth
        while (nodesAtCurrentDepth > 0) {
             struct node* current = queue[f++];
            if (current->left)
                queue[r++] = current->left;
            if (current->right)
                queue[r++] = current->right;

            nodesAtCurrentDepth--;
        }
        depth++;
    }
    return depth;
}
int LevelOrderTraversal( struct node* root)
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->arr = ( struct node*)malloc(sizeof( struct node)*20);
    q->size = 20;
    q->f = 0;
    q->r = 0;

    Enqueue(q,root);
    while(q->f != q->r)
        {

         struct node* current = q->arr[q->f];
        Enqueue(q, current->left);
        Enqueue(q, current->right);
        printf("%d \n", Dequeue(q));
    }
}
int printLeafNodes(struct node *root)
{
    if(root==NULL)
        return ;
    struct node** stack=(struct node**)malloc(sizeof(struct node*)* 1000);
    int top=-1;
    stack[++top]=root;
    while(top!=-1)
    {
        struct node* current=stack[top--];
        if(!current->left && !current->right)
        {
            printf("%d\n",current->data);
        }
    if(current->left)
        stack[++top]=current->left;
    if(current->right)
        stack[++top]=current->right;
    }
    free(stack);
}

int count_node( struct node* root) {
   if (root==NULL) {
        return 0;
    }
    return 1+count_node(root->left)+count_node(root->right);
}

struct node* deleteNode(struct node* root, int k)
{

    if (root == NULL)
        return root;
    if (root->data > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }


    if (root->left == NULL) {
        struct Node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }

    // If both children exist
    else {

        struct node* succParent = root;

        // Find successor
        struct node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }


        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        // Copy Successor Data to root
        root->data = succ->data;

        // Delete Successor and return root
        free(succ);
        return root;
    }
}
 int main()
 {
     int x,n;
     do
     {
         printf("1)Insert \n2)preorder \n3)Inorder \n4)postorder\n5)Mirror image \n6)Height\n7)LevelwiseTraversal\n8)Print leaf nodes\n9)Delete node\n10)Count nodes\n11)exit");
         printf("\nenter choice:");
         scanf("%d",&n);
         switch(n)
         {
             case 1:
             printf("Enter data:");
             scanf("%d",&x);
             root=insert(root,x);
             break;
             case 2:
             Preorder(root);
             break;
             case 3:
             Inorder(root);
             break;
             case 4:
             Postorder(root);
             break;
             case 5:
                mirror(root);
                Inorder(root);
                break;
             case 6:
                 printf("Height of BST: %d\n", height(root));
                break;
             case 7:
                LevelOrderTraversal(root);
                break;
             case 8:
                printf("\n",printLeafNodes(root));
                break;
             case 9:
                printf("Enter node to be deleted:");
                scanf("%d",&x);
                root=deleteNode(root,x);
                Inorder(root);
                break;
             case 10:
                  printf("Number of nodes in BST: %d\n", count_node(root));
                break;
             case 11:
                 return 0;
             break;
             default:
                printf("Invalid case");
                break;

         }
     }while(n!=0);

 }

