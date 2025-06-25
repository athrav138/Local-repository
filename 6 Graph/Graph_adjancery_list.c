#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* node = createNode(dest);
    node->next = graph->adjList[src];
    graph->adjList[src] = node;

    // For undirected graph
    node = createNode(src);
    node->next = graph->adjList[dest];
    graph->adjList[dest] = node;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("→ %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("Adjacency List:\n");
    printGraph(graph);
    return 0;
}
