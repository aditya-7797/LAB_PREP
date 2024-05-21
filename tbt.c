#include<stdio.h>
#include<stdlib.h>

struct TBT{

    int data;
    int lbit, rbit;
    struct TBT *left, *right;

};

void preorderTBT(struct TBT *head){

    struct TBT *p;
    p=head->left;

    while (p != head)
    {
        printf(" %d ", p->data);
        
        if(p->lbit==1){
            p=p->left;
        }
        else if(p->rbit==1){
            p=p->right;
        }
        else if(p->rbit==0){
            while (p->rbit==0 && p->right!=head)
                p=p->right;    
            p=p->right;
        }
    } 
}

struct TBT* insert(struct TBT *head, int data){

    struct TBT *temp,*p;
    temp = (struct TBT*) malloc(sizeof(struct TBT));
    temp->data=data;
    temp->lbit=temp->rbit=0;
    //temp->left=temp->right=NULL;
    
    if(head->lbit==0){
        head->left=temp;
        head->lbit=1;
        temp->left = head;
        temp->right = head;
        return head;
    }

    p = head->left;
    // find where to insert your data
    while (1)
    {
        if( data < p->data && p->lbit==1 ){
            p=p->left;
        }
        else if( data > p->data && p -> rbit==1 ){
            p=p->right;
        }
        else{
            break;
        }
    }

// to insert data into tree
    if(data < p->data){
        temp->right = p;
        temp->left = p->left;
        p->lbit = 1;
        p->left = temp;
    }

    if(data > p->data){
        temp->left=p;
        temp->right = p->right;
        p->rbit=1;
        p->right=temp;
    }
    return head;
}

int main(){
    struct TBT *head;
    head=(struct TBT*) malloc(sizeof(struct TBT));

    head->lbit=0;
    head->rbit=1;
    head->left=head->right=head;

    head = insert(head, 50);
    head = insert(head, 40);
    head = insert(head, 54);
    head = insert(head, 30);
    head = insert(head, 70);
    head = insert(head, 55);

    printf("traversing threaded binary tree: ");
    preorderTBT(head);

    printf("\nEnd of the progam.");

    return 0;
}