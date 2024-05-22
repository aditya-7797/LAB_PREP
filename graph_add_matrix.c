#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 3
#define MAX 20

int queue[MAX], rear, front;

void initialize() {
    front = rear = -1;
}

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void Enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}

int Dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}

void BFS(int start, int graph[V][V]) {
    initialize();
    Enqueue(start);
    int visited[V] = {0};
    visited[start] = 1;  // Mark the start vertex as visited

    while (!isEmpty()) {
        int i = Dequeue();
        printf(" %d ", i);

        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0 && !visited[j]) {
                Enqueue(j);
                visited[j] = 1;  // Mark as visited when enqueued
            }
        }
    }
    printf("\n");
}

void DFS(int i, int graph[V][V], int visited[V]) {
    printf(" %d ", i);
    visited[i] = 1;

    for (int j = 0; j < V; j++) {
        if (graph[i][j] != 0 && !visited[j]) {
            DFS(j, graph, visited);
        }
    }
}
int FindMin(int dist[V],bool visited[V]){
    int min_index,min=INT_MAX;
    for(int i=0;i<V;i++){
        if(visited[i]==false&&dist[i]<=min){
            min=dist[i];
            min_index=i;

        }
    }
    return min_index;
}
void Dijkstras(int graph[V][V]){
    int dist[V];
    bool visited[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[0]=0;
    for(int count =0;count<V-1;count++){
        int u=FindMin(dist,visited);
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(!visited[v]&&graph[u][v]&&dist[u]!=INT_MAX&& dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("\nvertices \t distance");
    for(int i=0;i<V;i++){
        printf("\n%d \t %d ",i,dist[i]);

    }
}
int main() {
    int graph[V][V] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };

    printf("BFS:\n");
    BFS(0, graph);

    int visited[V] = {0};
    printf("DFS:\n");
    DFS(0, graph, visited);

    printf("\nDijkstras algorithm :");
    Dijkstras(graph);
    return 0;
}