#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct stack
{
    int *arr;
    int top;
};
struct stack *create()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->arr = (int *)malloc(MAX * sizeof(int));
    s->top = -1;
    return s;
}
int isFull(struct stack *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *s, int key)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = key;
    }
    else
    {
        return;
    }
}
int pop(struct stack *s)
{
    int a = -1;
    if (!isEmpty(s))
    {
        int del = s->arr[s->top];
        s->top--;
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
    struct node *next;
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
void DFS(int sv, int v)
{
    struct stack *s = create();
    int visited[MAX];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    struct node *p;

    push(s, sv);

    while (!isEmpty(s))
    {
        int current = pop(s);
        if (!visited[current])
        {
            printf("%d ", current);
            visited[current] = 1;
            p = AL[current];

            while (p != NULL)
            {
                if (visited[p->vertex] == 0)
                {
                    push(s, p->vertex);
                }
                p = p->next;
            }

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
    DFS(sv, v);

    return 0;
}
