#include <stdio.h>
#include <stdlib.h>
#define MAX 999
int n;
int sv;

int MIN(int dist[], int visted[])
{
    int min = MAX, index;

    for (int i = 0; i < n; i++)
    {
        if (dist[i] < min && visted[i] == 0)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void prims(int G[n][n], int visited[], int dist[], int parent[])
{
    int u, mst = 0;
    dist[sv] = 0;

    for (int i = 0; i < n; i++)
    {
        u = MIN(dist, visited);
        visited[u] = 1;

        for (int j = 0; j < n; j++)
        {
            if (G[u][j] <= dist[j] && visited[j] == 0)
            {
                dist[j] = G[u][j];
                parent[j] = u;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {

        printf("%d->%d=%d\n", parent[i], i, dist[i]);
        mst += dist[i];
    }
    printf("%d", mst);
}
int main()
{
    printf("Enter the no of node in the graph\n");
    scanf("%d", &n);

    int G[n][n];

    printf("Enter the Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    int visited[n], dist[n], parent[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = MAX;
        parent[i] = -1;
    }
    printf("Enter the start vertex\n");
    scanf("%d", &sv);
    prims(G, visited, dist, parent);

    return 0;
}
