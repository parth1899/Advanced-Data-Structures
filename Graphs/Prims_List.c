#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
    int weight;
    int vertex;
    struct node *next;
};

struct node *AL[MAX];

void addedge(int v1, int v2, int weight)
{

    struct node *p;
    struct node *new;

    new = (struct node *)malloc(sizeof(struct node));
    new->vertex = v2;
    new->weight = weight;
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

int findmin(int visited[], int dist[], int n)
{
    int min = MAX, index;

    struct node *p;

    for (int i = 0; i < n; i++)
    {
        p = AL[i];

        while (p->next != NULL)
        {
            if (dist[p->vertex] < min && visited[p->vertex] == 0)
            {
                min = dist[p->vertex];
                index = p->vertex;
            }

            p = p->next;
        }
    }

    return index;
}

void prims(int n)
{
    int visited[n];
    int parent[n];
    int dist[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
        dist[i] = MAX;
    }
    int sv, u;
    printf("Enter the start vertex\n");
    scanf("%d", &sv);

    dist[sv] = 0;

    for (int i = 0; i < n; i++)
    {
        u = findmin(visited,dist, n);
        visited[u] = 1;
        struct node * p = AL[u];

        while (p != NULL)
        {
            if (p->weight < dist[p->vertex] && visited[p->vertex] == 0)
            {
                dist[p->vertex] = p->weight;
                parent[p->vertex] = u;
            }
            p = p->next;
        }
        
    }
    int mst =0;
        printf("Edge & weight\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d - %d %d\n", parent[i], i, dist[i]);
        mst += dist[i];
    }
    printf("MST=%d", mst);
}

int main()
{

    int vertices, v1, v2, edge, weight;

    printf("Enter the no of vertices\n");
    scanf("%d", &vertices);

    printf("Enter the node of edges\n");
    scanf("%d", &edge);

    for (int i = 0; i < edge; i++)
    {
        printf("Enter v1 and v2 of edge %d\n", i + 1);
        scanf("%d%d", &v1, &v2);

        printf("Enter weight\n");
        scanf("%d", &weight);

        addedge(v1, v2, weight);
        addedge(v2, v1, weight);
    }

    prims(vertices);

    return 0;
}
