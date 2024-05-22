#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left,*right;

};

struct stack{
    struct node *n;
    struct stack *next;
};



bool isStackEmpty(struct stack *top){
    if(top==NULL){
        return false;
    }else{
        return true;
    }
}

void push(struct node *temp, struct stack **top){
    struct stack *stn = (struct stack*)malloc(sizeof(struct stack));
    stn->next = *top;
    stn->n = temp;
    *top = stn;
}

struct node* pop(struct stack **top){
    struct stack *t1 = *top;
    struct node *temp = t1->n;
    *top = t1->next;
    free(t1);
    return temp;
}

void NonRecPostorder(struct node *root){

    struct stack *top=NULL;
    struct node *temp = root, *prev=NULL;

//pushing the left part of tree onto stack
    while (temp!=NULL)
    {
        push(temp, &top);
        temp = temp->left;
    }

    while(isStackEmpty(top)){
        temp = top->n;
        if(temp->right==NULL || temp->right == prev){
            printf(" %c ", temp->data);
            pop(&top);
            prev = temp;
        }else{
            temp = temp->right;
            while (temp!=NULL)
            {
                push(temp, &top);
                temp= temp->left;
            }
        }
    }
}

void nonRecPreorder(struct node *root){

    struct stack *node=NULL;
    struct node *temp;

    temp = root;

    while (temp!=NULL)
    {
        printf(" %c ", temp->data);
        push(temp, &node);
        temp = temp->left;
    }

    while (isStackEmpty(node))
    {
        temp = pop(&node);
        
        temp = temp->right;
        while (temp!=NULL)
        {
            printf(" %c ", temp->data);
            push(temp,&node);
            temp = temp->left;
        }
    }
}


void nonRecInorder(struct node *root){

    struct stack *node=NULL;
    struct node *temp;

    temp = root;

    while (temp!=NULL)
    {
        push(temp, &node);
        temp = temp->left;
    }

    while (isStackEmpty(node))
    {
        temp = pop(&node);
        printf(" %c ", temp->data);
        temp = temp->right;
        while (temp!=NULL)
        {
            push(temp,&node);
            temp = temp->left;
        }
    }
}

struct node* insert(struct node *root, int data){

    int asci = data;

    if(root==NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root->data = data;
        root->left=root->right=NULL;
        return root;
    }

    if(asci > root->data ){
       root->right= insert(root->right, data);
    }else{
        root->left = insert(root->left, data);
    }
}

int main(){

    struct node *root=NULL; 
    struct node *temp=NULL;
    root = temp = insert(root,'m');
    insert(root,'d');
    insert(root,'f');
    insert(root,'h');
    insert(root,'o');
    insert(root,'t');

    printf("\nTree traversal inorder: ");
    nonRecInorder(temp);

    printf("\nTree traversal preorder: ");
    nonRecPreorder(temp);

    printf("\nTree traversal postorder: ");
    NonRecPostorder(temp);

    return 0;
}