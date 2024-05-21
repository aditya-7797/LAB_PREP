#include<stdio.h>

Stack [100];
int top=-1;

int push(int num){
    top++;
    Stack[top]=num;
}

int pop(int num){
    return Stack[top--];
}


struct node{
    int data;
    struct node* left;
    struct node* right;
};

void inorder(struct node *root){
    
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        }
};

