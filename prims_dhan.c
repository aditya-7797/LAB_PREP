#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define N 3

void prims(int graph[N][N],int i){
    int no_of_edges=0;
    int visited[N]={0};
    int x,y;
    visited[i]=1;
    int count=0;
    while(no_of_edges<N-1){
        int min=INT_MAX;
        for(int i=0;i<N;i++){
            if(visited[i]){

                for(int j=0;j<N;j++){
                    if(!visited[j]&&graph[i][j]){
                        if(min>graph[i][j]){
                            min=graph[i][j];
                            x=i,y=j;

                        }

                    }
                }
            }
        }
        printf("\n%d , %d =%d",x,y,graph[x][y]);
        no_of_edges++;
        count+=graph[x][y];
        visited[y]=1;
        printf("count : %d",count);
    }

}
void krushkal(int graph[N][N]){
    int no_of_edges=0;
    int visited[N]={0};
    int x,y;
    while(no_of_edges<N-1){
        int min=INT_MAX;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visited[j]){
                    if(min>graph[i][j]){
                        min=graph[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }
        printf("\n %d %d => %d",x,y,graph[x][y]);
        visited[y]=1;
        visited[x]=1;
        graph[x][y]=INT_MAX;

    }
}
void main(){
    int graph[N][N]={
        {0,1,0},{1,0,1},{1,2,0}
    };
    printf("prims :\n");
    prims(graph,0);
    printf("krushkal : \n");
    krushkal(graph);

}