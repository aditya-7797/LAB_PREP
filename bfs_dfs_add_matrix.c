#include<stdio.h>

// Adjacency matrix for the graph
int a[7][7] = {
    {0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0, 1, 0}
};

// Array to keep track of visited nodes for DFS
int visited_dfs[7] = {0, 0, 0, 0, 0, 0, 0};

// Function for DFS traversal
void dfs(int i) {
    visited_dfs[i] = 1;
    printf("%d ", i);
    for (int j = 0; j < 7; j++) {
        if (a[i][j] == 1 && visited_dfs[j] == 0) {
            dfs(j);
        }
    }
}

// Function for BFS traversal
void bfs(int start) {
    int visited_bfs[7] = {0, 0, 0, 0, 0, 0, 0}; // Local visited array for BFS
    int queue[10], front = 0, rear = 0;

    visited_bfs[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        for (int j = 0; j < 7; j++) {
            if (a[currentNode][j] == 1 && visited_bfs[j] == 0) {
                visited_bfs[j] = 1;
                queue[rear++] = j;
            }
        }
    }
}

int main() {
    // Perform DFS starting from node 0
    printf("DFS Traversal: ");
    dfs(0);
    printf("\n");

    // Perform BFS starting from node 0
    printf("BFS Traversal: ");
    bfs(0);
    printf("\n");

    return 0;
}
