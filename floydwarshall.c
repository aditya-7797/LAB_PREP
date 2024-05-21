#include<stdio.h>
#include<stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floydwarshall(int n, int G[10][10]) {
    int i, j, k;

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main() {
    int i, j, n, G[10][10];

    printf("Enter the number of Vertices:- \n");
    scanf("%d", &n);

    printf("Enter the cost matrix:- \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    floydwarshall(n, G);

    printf("Final Matrix:- \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d \t", G[i][j]);
        }
        printf("\n");
    }

    return 0;
}
