#include <stdio.h>
#include <stdlib.h>
int n;
int ne = 0;
int parent[10];
int a, b;
int min;

int findParent(int x)
{
    if (x != parent[x])
    {
        x = parent[x];
    }
    return x;
}
void Union(int a, int b)
{
    int i = findParent(a);
    int j = findParent(b);
    parent[j] = i;
}
void kruskals(int adjmat[n][n])
{
    int mst = 0;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    while (ne < n - 1)
    {

        min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (parent[i] != parent[j] && adjmat[i][j] < min)
                {
                    min = adjmat[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        Union(a, b);
        ne++;

        printf("Edge %d : %d - %d = %d \n", ne, a, b, adjmat[a][b]);

        adjmat[a][b] = adjmat[b][a] = 999;
        mst += min;
    }
    printf("\n %d is min dist\n", mst);
}
int main()
{

    printf("Enter no of vertices\n");
    scanf("%d", &n);

    int adjMat[n][n];
    printf("Enter the Matrix\n");
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adjMat[i][j]);
        }
    }

    kruskals(adjMat);
    return 0;
}
