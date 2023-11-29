#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node
{
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Node* createNode(int vertex, int weight);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, int weight);
void dijkstra(Graph* graph, int src);
int findMinDistance(int distance[], bool sptSet[], int vertices);

int main() {
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("Edge %d - Enter source, destination and weight: ", i+1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    printf("Enter the source vertex: ");
    int src;
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}

Node* createNode(int vertex, int weight) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int findMinDistance(int distance[], bool sptSet[], int vertices) {
    int minValue = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < vertices; v++) {
        if (sptSet[v] == false && distance[v] <= minValue) {
            minValue = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(Graph* graph, int src) {
    int vertices = graph->numVertices;
    int distance[vertices];
    bool sptSet[vertices];

    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    distance[src] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int u = findMinDistance(distance, sptSet, vertices);

        sptSet[u] = true;

        Node* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            if (!sptSet[v] && distance[u] != INT_MAX && distance[u] + temp->weight < distance[v]) {
                distance[v] = distance[u] + temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

