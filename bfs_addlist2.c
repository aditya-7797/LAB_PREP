#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node *createNode(int key){
    
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=key;
    newnode->next=NULL;

    return newnode;

}

void addEdge(struct node *addlist[],int u,int v){
    struct node *newnode = createNode(v);
    newnode->next = addlist[u];
    addlist[u]= newnode;
}

struct node* bfs_traversal(struct node*addlist[],int startnode,int vertex,int visited[]){

    int queue[100];
    int front=0,rear=0;

    visited[startnode] = 1;
    queue[rear++] = startnode;

    while(front!= rear){

        int currentNode = queue[front++];
        printf("%d",currentNode);
    

    struct node *temp = addlist[currentNode];

    while(temp!=NULL){
        int neighbour=temp->data;
        if(!visited[neighbour]){
            visited[neighbour]=1;
            queue[rear++] = neighbour; 
        }
        temp= temp->next;
    }
}
};

struct node*dfs_traversal(struct node*addlist[],int node,int visited[]){


    visited[node]=1;
    printf("%d",node);

    struct node* temp= addlist[node];

    while(temp!=NULL){
        int neighbour= temp->data;
        if(!visited[neighbour]){
            dfs_traversal(addlist,neighbour,visited);
        }
        temp=temp->next;
    }
}

int main(){

    int vertex = 5;

    struct node*addlist[vertex];
    for(int i=0;i<vertex;i++)
        addlist[i]=NULL;
    

    addEdge(addlist,0,1);
    addEdge(addlist,0,2);
    addEdge(addlist,1,3);
    addEdge(addlist,1,2);
    addEdge(addlist,2,3);

    int visited[vertex];
    for(int i=0;i<vertex;i++)
    visited[i]=0;

    bfs_traversal(addlist,0,vertex,visited);

    for(int i=0;i<vertex;i++)
    visited[i]=0;

    dfs_traversal(addlist,0,visited);

    return 0;
}