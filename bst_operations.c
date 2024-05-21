//4. WAP to perform following operations on BST. a. Create b. Insert c. Delete d. Mirror Image e. Level wise Display f. Height of the tree g. Display Leaf Nodes.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	struct node *left, *right;
	int data;
};
struct queue{
	
	struct node *data;
	struct queue *next;
};
struct stack{
	struct node *T;
	struct stack *next;
};
void push(struct node *temp, struct stack **top){
	struct stack *s = (struct stack*) malloc (sizeof(struct stack));
	s->next = (*top);
	s->T = temp;
	(*top) = s;
}
struct node* pop(struct stack **top){
	struct stack *temp = (*top);
	struct node *ret = (*top)->T;
	(*top) = (*top)->next;
	free(temp);
	return ret;
}
bool emptyStack(struct stack *top){
	if(top == NULL)
		return true;
	else
		return false;
}
void enQueue(struct node *data, struct queue **front,struct queue **rear){
	if(data == NULL)
		return;
	struct queue *temp = (struct queue*) malloc (sizeof(struct queue));
	temp->data = data;
	temp->next = NULL;
	if((*front) == NULL){
		(*front) = temp;
		(*front)->next = NULL;
		(*rear) = temp;
		(*rear)->next = NULL;
		return;
	}
	(*rear)->next = temp;
	(*rear) = temp;
}
struct node* deQueue(struct queue **front){
	struct node *temp = (*front)->data;
	struct queue *temp2 = (*front);
	(*front) = temp2->next;
	free(temp2);
	return temp;
} 
struct node* insert(struct node *root, int data){
	struct node *temp, *parent = NULL, *traversal = root;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	while(traversal != NULL){
		parent = traversal;
		if(traversal->data > data)
			traversal = traversal->left;
		else
			traversal = traversal->right;
	}
	if(parent == NULL)
		root = temp;
	else if(parent->data > data)
		parent->left = temp;
	else
		parent->right = temp;
	return root;
}
void levelWise(struct node *root){
	struct queue *front = NULL, *rear = NULL;
	struct node *temp;
	enQueue(root, &front, &rear);
	while(front != NULL){
		temp = deQueue(&front);
		printf("%d ",temp->data);
		enQueue(temp->left, &front, &rear);
		enQueue(temp->right, &front, &rear);
	}
}
void leafNodes(struct node *root){
	struct stack *top = NULL;
	while(root!=NULL){
		push(root, &top);
		root = root->left;
	}
	while(!emptyStack(top)){
		root = pop(&top);
		if(root->left == NULL && root->right == NULL)
			printf("%d ",root->data);
		root = root->right;
		while(root!=NULL){
			push(root, &top);
			root = root->left;
		}
	}
}
struct node* getRoot(struct node *root){
	root = root->right;
	while(root->left != NULL)
		root = root->left;
	return root;
}
struct node* deletion(struct node *root, int key){
	if(root == NULL){
		return root;
	}
	else if(root->data > key)
		root->left = deletion(root->left, key);
	else if(root->data < key)
		root->right = deletion(root->right, key);
	else{
		if(root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		else{
			struct node *temp = getRoot(root);
			root->data = temp->data;
			root->right = deletion(root->right, root->data);
		}
	}	
}
struct node* mirror(struct node *root){
	struct stack *top = NULL;
	struct node *temp, *curr = root;
	push(curr, &top);
	while(!emptyStack(top)){
		curr = pop(&top);
		temp = curr->left;
		curr->left = curr->right;
		curr->right = temp;
		if(curr->left != NULL)
			push(curr->left,&top);
		if(curr->right != NULL)
			push(curr->right,&top);
	}
	return root;
}
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
int getHeight(struct node *root){
	if(root->left == NULL && root->right == NULL) 
		return 0;
	return (max(getHeight(root->left), getHeight(root->right)))+1;
}

int main(){
	struct node *root = NULL;
	root = insert(root, 35);
	root = insert(root, 20);
	root = insert(root, 22);
	root = insert(root, 49);
	root = insert(root, 13);
	root = insert(root, 27);
	root = insert(root, 37);
	root = insert(root, 51);
	root = insert(root, 7);
	root = insert(root, 18);
	printf("Orginal Tree LevelWise Traversing:- ");
	levelWise(root);
	printf("\n\nTree after deletion of 22:- ");
	root = deletion(root, 22);
	levelWise(root);
	printf("\n\nLeaf Nodes Present are:- ");
	leafNodes(root);
	printf("\n\nOrginal Tree After Mirroring:- ");
	root = mirror(root);
	levelWise(root);
	printf("\n\nHeight is: %d", getHeight(root));
}

