#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *left, *right;
};

struct BST* deleteNode(struct BST *root, int delete){

    struct BST *temp;

    if(root==NULL){
        return root;
    }
    else if(delete < root->data){
        root->left = deleteNode(root->left, delete);
    }
    else if(delete > root->data){
        root->right = deleteNode(root->right, delete);
    }else{
        // delete if has 0 or 1 child
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }

        // to delete if 2 child
        temp = root->right;
        while (temp->left!=NULL)
            temp=temp->left;
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);   
    }
    
    return root;
}

void search_ele(struct BST *root, int search){
  if (root == NULL) {
        printf("Element not found\n");
        return;
    }

    if (search == root->data) {
        printf("Element found in tree.\n");
        return;
    }

    if (search > root->data) {
        search_ele(root->right, search);
    } else {
        search_ele(root->left, search);
    }
}

void inorder(struct BST *root){

    if(root==NULL) return;

    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

struct BST* insert(struct BST *root, int data){

    if(root==NULL){
        root = (struct BST*) malloc(sizeof(struct BST));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    } 
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    else if(data < root->data){
        root->left = insert(root->left, data);
    }

    return root;
}

int main(){

    struct BST *root=NULL;
    int search;

    root=insert(root, 50);
    root=insert(root, 57);
    root=insert(root, 30);
    root=insert(root, 20);
    root=insert(root, 35);
    root=insert(root, 75);

    printf("Inorder traversal");
    inorder(root); 

    printf("\nEnter element to search: ");
    scanf("%d", &search);
    search_ele(root, search);
    deleteNode(root, search);

    printf("\nInorder traversal after deletion: ");
    inorder(root); 

    return 0;
}

