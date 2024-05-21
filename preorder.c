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

struct node* pop(struct stack **top){
    struct stack *t1 = *top;
    struct node *tmp = t1->n;
    *top = t1->next;
    free(t1);
    return tmp;
}

void push(struct node *tmp, struct stack **top){
    struct stack *stn = (struct stack*) malloc(sizeof(struct stack));
    stn->next = top;
    stn->n = tmp;
    *top = stn;
}

bool isStackEmpty(struct stack *top){
    if(top==NULL){
        return false;
    }else{
        return true;
    }
}


void nonRecPreorder(struct node *root){
    struct stack *top = NULL;
    struct node *tmp;

    tmp = root;

    while (tmp!=NULL)
    {
        printf(" %c ", tmp->data);
        push(tmp, &top);
        tmp = tmp->left;
    }

    while (isStackEmpty(top))
    {
        tmp = pop(&top);
        tmp = tmp->right;
        while (tmp!=NULL)
        {
            printf("%c", tmp->data);
            push(tmp, &top);
            tmp=tmp->left;
        }
    }
}

void preorder(struct node *root){

    if(root==NULL) return;

    printf(" %c ", root->data);
    preorder(root->left);
    preorder(root->right);

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
    root = insert(root,'d');
    root = insert(root,'f');
    root = insert(root,'h');
    root = insert(root,'o');
    root = insert(root,'t');

    preorder(temp);

    return 0;
}