#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct queue
{
    int *arr;
    int front;
    int rear;
};
struct queue *createq()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->arr = (int *)malloc(MAX * sizeof(int));
    q->rear = 0;
    q->front = 0;
    return q;
}
int isFull(struct queue *q)
{
    if (q->rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Enqueue(struct queue *q, int key)
{
    if (!isFull(q))
    {
        q->rear++;
        q->arr[q->rear] = key;
    }
    else
    {
        return;
    }
}
int Dequeue(struct queue *q)
{
    int a = -1;
    if (!isEmpty(q))
    {
        q->front++;
        int del = q->arr[q->front];
        return del;
    }
    else
    {
        return a;
    }
}
struct node
{
    int vertex;
    struct node * next;
};

struct node *AL[MAX];

void addEdge(int v1, int v2)
{
    struct node *p;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->vertex = v2;
    new->next = NULL;
    p = AL[v1];
    if (p == NULL)
    {
        AL[v1] = new;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = new;
    }
}
void BFS(int sv, int v)
{
    struct queue *q;
    struct node *p;
    q = createq();
    int visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    visited[sv] = 1;
    Enqueue(q, sv);

    while (!isEmpty(q))
    {
        int del = Dequeue(q);
        printf("%d ", del);
        p = AL[del];

        while (p != NULL)
        {
            if (visited[p->vertex] == 0)
            {
                Enqueue(q,p->vertex);
                visited[p->vertex] = 1;
            }
           p = p->next; 
        }
    }
}

int main()
{
    int v, e, v1, v2;
    printf("Enter Vertices\n");
    scanf("%d", &v);

    printf("Enter Edges\n");
    scanf("%d", &e);

    for (int i = 0; i < e; i++)
    {
        printf("Enter v1 and v2 for edge %d\n", i + 1);
        scanf("%d %d", &v1, &v2);
        addEdge(v1, v2);
        addEdge(v2, v1);
    }
    int sv;
    printf("Start vertex\n");
    scanf("%d", &sv);
    BFS(sv,v);

    return 0;
}
// 0 1
// 0 2
// 0 3
// 1 2
// 2 3
// 2 4
// 3 4
// 4 5
// 4 6

