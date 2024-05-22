#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent a graph. A graph is an array of adjacency lists.
// The size of the array will be V (number of vertices in the graph)
struct Graph {
    int V;
    int E;
    struct AdjList* array;
};

// Structure to represent an edge
struct Edge {
    int src;
    int dest;
    int weight;
};

// Utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Utility function to create a graph of V vertices
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Utility function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Comparator function for sorting edges by weight
int comparator(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

// Utility function to find set of an element i (uses path compression technique)
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

// A function that does union of two sets of x and y (uses union by rank)
void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// The main function to construct MST using Kruskal's algorithm
void kruskalAlgo(struct Graph* graph) {
    int V = graph->V;
    struct Edge edges[graph->E];
    int edge_count = 0;

    // Extract all edges from the adjacency list
    for (int v = 0; v < V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl) {
            if (v < pCrawl->dest) { // To avoid duplicates, consider only one direction
                edges[edge_count].src = v;
                edges[edge_count].dest = pCrawl->dest;
                edges[edge_count].weight = pCrawl->weight;
                edge_count++;
            }
            pCrawl = pCrawl->next;
        }
    }

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, graph->E, sizeof(edges[0]), comparator);

    int parent[V];
    int rank[V];

    // Allocate memory for creating V subsets
    for (int v = 0; v < V; ++v) {
        parent[v] = v;
        rank[v] = 0;
    }

    int minCost = 0; // Initialize result

    printf("Following are the edges in the constructed MST\n");

    for (int i = 0; i < edge_count; ++i) {
        int u = findParent(parent, edges[i].src);
        int v = findParent(parent, edges[i].dest);

        if (u != v) {
            unionSet(parent, rank, u, v);
            printf("%d -- %d == %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            minCost += edges[i].weight;
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() {
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 4);

    kruskalAlgo(graph);

    return 0;
}
