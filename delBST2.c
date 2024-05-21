// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node*left,*right;
// };

// struct node *insert(struct node* root,int value){
    
//     if(root==NULL){
//         root=(struct node*)malloc(sizeof(struct node));
//         root->data=value;
//         root->left=root->right=NULL;
//     }

//     else if (value>root->data)
//     {
//         root->right=insert(root->right,value);
//     }

//     else{
//         root->left=insert(root->left,value);
//     }

//     return root;
    
// }

// struct node* delete_BST(struct node*root,int key){
    

//     struct node* temp;
//     if(root==NULL){
//         return root;
//     }

//     else if (key>root->data)
//     {
//         root->right= delete_BST(root->right,key);
//     }

//     else if (key<root->data)
//     {
//         root->left= delete_BST(root->left,key);
//     }

//     else{
//         if(root->left==NULL){
//             temp=root->right;
//             free (root);
//             return temp;
//         }

//         else if (root->right==NULL)
//         {
//             temp=root->left;
//             free(root);
//             return temp;
//         }

//         temp=root->right;
//         while(temp->left!=NULL)
//             temp=temp->left;
    
//         root->data = temp->data;
//         root->right = delete_BST(root->right, temp->data);
        
//     }

//     return root;
    
// }

// void search_BST(struct node*root,int src){

//     if(root==NULL){
//         printf("Element not found");
//         return;
//     }

//     if(root->data==src){
//         printf("element found");
//         return;
//     }

//     else if (src>root->data)
//     {
//         search_BST(root->right,src);
//     }

//     else{
//         search_BST(root->left,src);
//     }
    


// }

// void inorder(struct node*root){

//     if(root==NULL){
//         return;
//     }

//     inorder(root->left);
//     printf("%d", root->data);
//     inorder(root->right);


// }

// int main(){

//     struct node*root=NULL;
//     int src;

//     root=insert(root,50);
//     root=insert(root,58);
//     root=insert(root,40);
//     root=insert(root,34);
//     root=insert(root,64);
//     root=insert(root,72);

//     inorder(root);
//     printf("\n");


//     search_BST(root,34);
//     printf("\n");

//     root = delete_BST(root,64);
//     root = delete_BST(root,40);

//     inorder(root);
// }

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = value;  // Fixed initialization of root->data
        root->left = root->right = NULL;
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }

    return root;
}

struct node *delete_BST(struct node *root, int key) {
    struct node *temp;
    if (root == NULL) {
        return root;
    }

    if (key > root->data) {
        root->right = delete_BST(root->right, key);
    } else if (key < root->data) {
        root->left = delete_BST(root->left, key);
    } else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = delete_BST(root->right, temp->data);
    }

    return root;
}

void search_BST(struct node *root, int src) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }

    if (root->data == src) {
        printf("Element found\n");
        return;
    } else if (src > root->data) {
        search_BST(root->right, src);
    } else {
        search_BST(root->left, src);
    }
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);  // Added space for better readability
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    int src;

    root = insert(root, 50);
    root = insert(root, 58);
    root = insert(root, 40);
    root = insert(root, 34);
    root = insert(root, 64);
    root = insert(root, 72);

    printf("Inorder traversal before deletion:\n");
    inorder(root);
    printf("\n");

    printf("Searching for element 34:\n");
    search_BST(root, 34);
    printf("\n");

    root = delete_BST(root, 64);  // Need to reassign the root after deletion
    root = delete_BST(root, 40);

    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    return 0;
}








