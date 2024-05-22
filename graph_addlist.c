#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 30
int queue[MAX];
int front,rear;



void initialized(){
    front=rear=-1;
}
int isEmpty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
void Enqueue(int data){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    if(isEmpty()){
        front=rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=data;
}

int Dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    int data=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    return data;
}



struct Edge
{
    int src,dest,wt; 
};
struct Node{

    struct Edge edge;
    struct Node *next;

};
struct Node *createNode(int src,int dest,int wt)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->edge.src=src;
    newNode->edge.dest=dest;
    newNode->edge.wt=wt;
    newNode->next=NULL;

    return newNode;
}

void createGraph(struct Node *graph[],int V){
    for(int i=0;i<V;i++){
        graph[i]=NULL;
    }

    
    graph[0]=createNode(0,1,1);
    graph[0]->next=createNode(0,2,1);
    // graph[0]->next->next=createNode(0,3,1);

    graph[1]=createNode(1,0,1);
    graph[1]->next=createNode(1,3,1);
    // graph[1]->next->next=createNode(1,3,1);

    graph[2]=createNode(2,0,1);
    graph[2]->next=createNode(2,4,1);
    // graph[2]->next->next=createNode(2,0,1);


    graph[3]=createNode(3,1,1);
    graph[3]->next=createNode(3,5,1);


    graph[4]=createNode(4,2,1);
    graph[4]->next=createNode(4,5,1);

    graph[5]=createNode(5,3,1);
    graph[5]->next=createNode(5,4,1);
    graph[5]->next->next=createNode(5,6,1);


    graph[6]=createNode(6,5,1);


}

void print(struct Node *graph[],int V){
    struct Node *T;
    for(int i=0;i<V;i++){
        T=graph[i];
        printf("\n edges for %d node is ",i);
        while(T!=NULL){

             printf("\t  %d ",T->edge.dest);
             T=T->next;
        }
        
        
    }
}
void findNeighbour(struct Node *graph[],int node){
    struct Node *temp=graph[node];
    printf("\n Nieghbours of %d is : ",node);
    while(temp!=NULL){
        printf("\n%d \t %d  ",temp->edge.dest,temp->edge.wt);
        temp=temp->next;
    }
} 

void BFS(struct Node *graph[], int V) {
    bool visited[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    initialized();
    Enqueue(0);
    while (!isEmpty()) {
        int current = Dequeue();
        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = true;
            struct Node *node = graph[current];
            while (node!=NULL) {
                
                    Enqueue(node->edge.dest);
                
                node=node->next;
            }
        }
    }
}
void DFS(struct Node *graph[],int cur,bool vis[]){
    if(vis[cur]==true){
        return;
    }
    printf("%d ",cur);
    vis[cur]=true;

    struct Node *T=graph[cur];
    while(T!=NULL){
        if(vis[T->edge.dest]==false){

            DFS(graph,T->edge.dest,vis);
        }
        T=T->next;
    }


}

struct Node *PrintAllPath(struct Node *graph[],int curr,int tar,bool vis[],char path[]){
    if(curr==tar){
        printf("%s\n",path);
        return;
    }


    struct Node *T=graph[curr];

    while(T!=NULL){

        if(vis[T->edge.dest]==false){

            vis[curr]=true;
            char newPath[1000];
            strcpy(newPath,path);
            char buffer[10];
            sprintf(buffer,"%d->",T->edge.dest);
            strcat(newPath,buffer);

            PrintAllPath(graph,T->edge.dest,tar,vis,newPath);
            vis[curr]=true;
        }


        T=T->next;
    }

}

void main(){


    int V=7;
    struct Node *graph[V];
     

    createGraph(graph,V);
    print(graph,V);

    findNeighbour(graph,2);

    // bool visit[V];
    // for(int i=0;i<V;i++){
    //     if(visit[i]==false){
    //         BFS(graph,V,i,visit[]);
    //     }
    // }
    printf("\nBFS TRAVERSAL :\n ");
    BFS(graph,V);

    bool vis[V];
    for(int i=0;i<V;i++){
        vis[i]=false;
    }
    int cur=0;

    printf("\nDFS TRAVERSAL :\n");
    DFS(graph,cur,vis);

    int curr=0,tar=5;
    bool vis1[V];
    char path[1000];
    sprintf(path,"%d->",0);
    printf("\nPRINT ALL PATH :\n");
    PrintAllPath(graph,curr,tar,vis1,path);


}