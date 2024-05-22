#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 20

int top,top1,count=0;
struct Node *stack[MAX];
struct Node *stack1[MAX];

struct Node *queue[MAX];
int front,rear;


void iniatiliazedQueue(){
    front=rear=-1;
}
int isQueueEmpty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isQueueFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
void Enqueue(struct Node *data){
    if(front==-1){
        front=rear=0;
        queue[rear]=data;
    }
    else{
        queue[++rear]=data;
    }
}
struct Node * Dequeue(){
    struct Node *data;
    data=queue[front];
    if(front==rear){
        front=rear=-1;
    }else{
        front++;
    }
    return data;
}

void initialized(){
    top = -1;
    top1 = -1;
}


int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty1(){
    if(top1 == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull1(){
    if(top1 == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}


void push(struct Node *data){
    if(isFull() == 0){
        stack[++top] = data;
    }
    else{
        printf("stack overflow!!!!");
    }
}

void push1(struct Node *data){
    if(isFull1() == 0){
        stack1[++top1] = data;
    }
    else{
        printf("stack overflow!!!!");
    }
}

struct Node *pop(){
    struct Node *data;
    if(isEmpty() == 0){
        data = stack[top--];
        return  data;
    }
    else{
        printf("stack underflow!!!!");
        return NULL; // added return for consistency
    }
}
struct Node *pop1(){
    struct Node *data;
    if(isEmpty1() == 0){
        data = stack1[top1--];
        return  data;
    }
    else{
        printf("stack underflow!!!!");
        return NULL;
    }
}

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data){
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

struct Node *insert(struct Node *node,int data){
    if(node == NULL){
        return newNode(data);
    }

    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

void preorder(struct Node *node){
    struct Node *T = node;
    while(T != NULL){
        printf("%d  ", T->data);
        push(T);
        T = T->left;
        count++;
    }

    while(isEmpty() == 0){
        T = pop();
        T = T->right;
        while(T != NULL){
            printf("%d  ", T->data);
            push(T);
            T = T->left;
            count++;
        }
    }
}

void inorder(struct Node* node){
    struct Node *T = node;

    while(T!=NULL){
        push(T);
        T = T->left;


    }

    while(!isEmpty()){
        T=pop();
        printf("%d  ",T->data);
        T=T->right;
        while(T!=NULL){
            push(T);
            T = T->left;


        }

    }
   
}
void postorder(struct Node *node){
    if (node == NULL)
        return;

    struct Node *T = node;
    push(T);

    while (!isEmpty()) {
        T = pop();
        push1(T); // Push onto the second stack for postorder traversal

        if (T->left != NULL)
            push(T->left); // Push left child first
        if (T->right != NULL)
            push(T->right); // Push right child second
    }

    while (!isEmpty1()) {
        T = pop1(); // Pop from the second stack for postorder traversal
        printf("%d  ", T->data);
    }
}

void BFS(struct Node *node)
{
    if (node == NULL)
        return;
    struct Node *T=node;
    iniatiliazedQueue();
    Enqueue(T);
   // Enqueue(NULL);
    while(!isQueueEmpty()){
        T=Dequeue();
        // if(T->data==NULL){
        //     printf("\n");
        //     if(!isQueueEmpty()){
        //         Enqueue(NULL);
        //     }
        //     else{
        //         break;
        //     }
        // }
        // else{
            printf("%d ",T->data);
            if(T->left!=NULL){
                Enqueue(T->left);
            }
            if (T->right!=NULL){
                Enqueue(T->right);
            }

        // }
    }

}

int TotalNoOfNodes(struct Node *node){


    if(node==NULL){
        return 0;
    }
    int leftNodes=TotalNoOfNodes(node->left);
    int rightNodes=TotalNoOfNodes(node->right);

    return leftNodes+rightNodes+1;

}
int max(int left,int right){
    return (left>right)?left :right;
}
int HeightOfTree(struct Node *node){

    if(node==NULL){
        return 0;
    }
    int leftHeight=HeightOfTree(node->left);
    int rightHeight=HeightOfTree(node->right);


    int myheight=max(leftHeight,rightHeight) +1;


    return myheight;

}
int SumOfNodes(struct Node *node){
    if(node==NULL){
        return 0;
    }
    int leftSum=SumOfNodes(node->left);
    int rightSum=SumOfNodes(node->right);

    return leftSum+rightSum+node->data;

}
 struct Node *Find(struct Node *node,int data){

    
    struct Node *T=node;
    if(T==NULL||T->data==data){
        return T;
    }
    if(data<T->data){
        return Find(T->left,data);
    }
    else if(data>T->data){
        return Find(T->right,data);
    }
   

}
// struct Node *delete(struct Node *node,int data){
//     struct Node *prev;
//     if(node!=NULL){
//         if(data > node->data){
//             prev=node;
//             node->right=delete(node->right,data);
            
//         }
//         else if(data < node->data){
//             prev=node;
//             node->left=delete(node->left,data);
            
//         }
//         if(node->left
//         )

//     }

// }
struct Node *FindMin(struct Node *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->left!=NULL){
        return FindMin(root->left);

    }
    return root;
}
struct Node *delete(struct Node *root,int x){
    if(root==NULL){
        return NULL;
    }

    if(x<root->data){
        root->left=delete(root->left,x);
    }
    else if(x>root->data){
        root->right=delete(root->right,x);
    }
    else{
        if(root->left==NULL&& root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            struct Node *temp;
            if(root->left==NULL){
                temp=root->right;

            }else{
                temp=root->left;

            }
            free(root);
            return temp;
        }
        else{
            struct Node *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);

        }
    }
    return root;







}
void main(){
    initialized();

    struct Node *root = NULL;
    // root=newNode(10);
    // root->left=newNode(20);
    // root->right=newNode(30);
    // root->left->left=newNode(40);
    // root->left->right=newNode(50);
    // root->right->left=newNode(60);
    // root->right->right=newNode(70);
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);

    printf("\nPreorder traversal : ");
    preorder(root);

    printf("\nInorder traversal : ");
    inorder(root);

    printf("\nPostorder traversal : ");
    postorder(root);

    printf("\nnumber of nodes : %d",count);
    
    printf("\nLevel wise traversal : ");
    BFS(root);

    int cnt=TotalNoOfNodes(root);
    printf("\nnumber of nodes recursion : %d",cnt);

    int height=HeightOfTree(root);
    printf("\nHeight of tree : %d",height);

    int sum=SumOfNodes(root);
    printf("\nSum of node : %d",sum);

    int key=60;
    if(Find(root,key)==NULL){
        printf("\n%d not found ",key);
    }else{

        printf("\n%d found", key);
    }
    
    insert(root, 5);
    insert(root, 15);
    insert(root,9);
    insert(root,8 );
    insert(root,3 );
    

     printf("\npreorder traversal : ");
    preorder(root);
    // delete(root,70);
    struct Node *deletedNode=delete(root,60);
    printf("\nafter deletion of node 60 :\n");
    inorder(root);



}