#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *insert_bst(struct node*root, int value){
    
    if(root==NULL){
        
        root=(struct node*)malloc(sizeof(struct node*));

        root->data=value;
        root->right=root->left=NULL;

        return root;

    }

    else if(value>root->data)
{
    root->right=insert_bst(root->right,value);
}

else if (value<root->data)
{
    root->left=insert_bst(root->left,value);
}
};

void main(){

    struct node*root = NULL;
    insert_bst(root,10);
    insert_bst(root,5);
}

struct node* preorder(struct node*root){
    
    if(root!=NULL){

    preorder(root->left);
    printf("%d",root->data);
    preorder(root->right);
    
    };
    return ;
}