#include<stdio.h>

// Stack[10]; 
// int top=-1;

// void push(int num){

//     if(top == 10){
//         printf("Stack is full\n");
//     }
//     else{
//         Stack[++top]= num;
//     }
// }

// int pop(){

//     if(top == -1){
//         printf("Stack is empty");
//     }
//     else{
//         return Stack[top--];
//     }

// }

// void peek(){
//     if(top == -1){
//         printf("Stack is empty");
// }
// else{
//     printf("Top element is %d\n",Stack[top]);
// }
// }

// void display(){
//     for(int i=0;i<=top;i++){
//         printf("%d\n",Stack[i]);
//     }
// }

int visited[7] = {0,0,0,0,0,0,0,} ;

    int a [7] [7] = {
        {0,1,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {0,1,0,1,1,0,0},
        {0,0,1,0,1,0,0},
        {1,0,0,1,0,1,0},
        {0,0,0,0,1,0,1},
        {1,1,0,0,0,1,0}
        };
void dfs(int i){
    visited[i] = 1;
    printf("%d ",i);
    for(int j=0;j<7;j++){
        if(a[i][j] == 1 && visited[j] == 0){
            dfs(j);
            }
}    
}

void main(){

    // push(1);
    // push(2);
    // push(4);
    // push(6);  
    // push(9);
    // push(3);

    // display();

    // pop();
    // pop();

    // display();

    // peek();

    dfs(0);

  
    }
