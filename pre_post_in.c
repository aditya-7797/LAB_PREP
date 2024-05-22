#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int data){
    struct Node *tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->data=data;
    tmp->left=tmp->right=NULL;
    return tmp;
};
// struct Node insert(struct Node root,int data){
//     struct Node* node=newNode(data);
//     return node;
// }


void preorder(struct Node *node){
    if(node==NULL){
        return;
    }
    printf("%d  ",node->data);
    preorder(node->left);
    preorder(node->right);

}

void inorder(struct Node *node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    printf("%d  ",node->data);
    inorder(node->right);

}

void postorder(struct Node *node){
    if(node==NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d  ",node->data);

}
void main(){
    struct Node *root=NULL;
    root=newNode(10);
    root->left=newNode(20);
    root->right=newNode(30);
    root->left->left=newNode(40);
    root->left->right=newNode(50);
    root->right->left=newNode(60);
    root->right->right=newNode(70);


    printf("\nPreorder traversal : ");
    preorder(root);
    printf("\nInorder traversal : ");
    inorder(root);
    printf("\nPostorder traversal : ");
    postorder(root);
}