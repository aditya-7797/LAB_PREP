// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node*left,*right;
//     int height;
// };

// int max(int a,int b){
//     if(a>b){
//         return a;
//     }
//     else{
//         return b;
//     }
// }

// int height(struct node *N){
//     if(N==NULL){
//         return;
//     }
//     return N->height;

// }

// int get_balance1(struct node *N){
//     if(N == NULL){
//         return;
//     }
//     return height(N->left) - height(N->right);
// }

// struct node *createNode(int key){

//     struct node* NewNode = (struct node*)malloc(sizeof(struct node));

//     NewNode->data = key;
//     NewNode->left=NewNode->right=NULL;
//     NewNode->height=1;

//     return NewNode;
// }

// struct node *rightRoatation(struct node*y){
    
//     struct node *x = y->left;
//     struct node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     x->height = max(height(x->left),height(x->right))+1;
//     y->height = max(height(y->left),height(y->right))+1;

//     return x;
// }

// struct node *leftRoatation(struct node*x){
    
//     struct node *y = x->left;
//     struct node *T2 = y->right;

//     y->right = x;
//     x->left = T2;

//     x->height = max(height(x->left),height(x->right))+1;
//     y->height = max(height(y->left),height(y->right))+1;

//     return y;
// }

// struct node *insert(struct node *root, int key){

//     if(root==NULL){
//         return(createNode(key));
//     }

//     if (key>root->data){
//         root->right=insert_node(root->right,key);
//     }
//     else if (key<root->data){
//         root->left=insert_node(root->left,key);
//     }
//     else{
//         return root;
//     }

//     root->height= 1+ max(height(root->left),height(root->right));

//     int balance = get_balance1(root);

//     if(balance>1 && key< root->left->data){
//        return rightRoatation(root);
//     }
//     if(balance<-1 && key> root->right->data)
//         return leftRoatation(root);
    

//     if(balance>1 && key> root->left->data){
        
//             root->left=leftRoatation(root->left);
//             return rightRoatation(root);
        
//     }

//     if (balance < -1 && key < root->right->data) 
// 	{ 
// 		root->right = rightRotate(root->right); 
// 		return leftRotate(root); 
// 	} 

//     return root;

// }

// void preOrder(struct Node *root) 
// { 
// 	if(root != NULL) 
// 	{ 
// 		printf("%d ", root->key); 
// 		preOrder(root->left); 
// 		preOrder(root->right); 
// 	} 
// } 

// /* Driver program to test above function*/
// int main() 
// { 
// struct Node *root = NULL; 

// /* Constructing tree given in the above figure */
// root = insert(root, 10); 
// root = insert(root, 20); 
// root = insert(root, 30); 
// root = insert(root, 40); 
// root = insert(root, 50); 
// root = insert(root, 25); 

// /* The constructed AVL Tree would be 
// 			30 
// 		/ \ 
// 		20 40 
// 		/ \	 \ 
// 	10 25 50 
// */

// printf("Preorder traversal of the constructed AVL"
// 		" tree is \n"); 
// preOrder(root); 

// return 0; 
// } 


#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
    int height;
};

// Function to get the height of the tree
int height(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to create a new node
struct node* createNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return(node);
}

// Function to right rotate subtree rooted with y
struct node* rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
struct node* leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct node* insert(struct node* node, int key) {
    /* 1. Perform the normal BST rotation */
    if (node == NULL)
        return(createNode(key));

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Driver program to test above function */
int main() {
    struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
                30
               /  \
             20   40
            /  \     \
           10  25    50
    */

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
}
