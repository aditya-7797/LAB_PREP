#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left,*right;
};


struct node * create(){
  struct node *newNode;
  int data;
  
  newNode = (struct node *)malloc(sizeof(struct node));

  printf("Enter a data");
  scanf("%d",&data);
  
  
  if(data==-1){
    return 0;
  };
  
  newNode->data= data;
  printf("Enter the left child of data\n");
  newNode->left=create();
  
  printf("Enter the right child of data\n");
  newNode->right= create();
  
  return newNode;
  
};


int main()
{
  struct node *root=NULL;
  root=create();
};