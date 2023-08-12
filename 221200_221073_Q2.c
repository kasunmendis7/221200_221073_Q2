#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int data);
bool isSymmetric(struct Node* root);
struct Node* insertLeft(struct Node* root, int data);
struct Node* insertRight(struct Node* root, int data);
bool isSymmetricalCheck(struct Node* rootRight, struct Node* rootLeft);

int main() {
  int r, l, n, j;
  printf("How many 'node pairs' do you want to enter(other than the root node): ");
  scanf("%d", &n);
  printf("Insert data into the root node: ");
  scanf("%d", &j);
  struct Node* root = newNode(j);
  for (int i = 0; i < n; i++) {
    printf("Insert data into the right node: ");
    scanf("%d", &r);
    insertRight(root, r);
    printf("Insert data into the left node: ");
    scanf("%d", &l);
    insertLeft(root, l);
  }
  if(isSymmetric(root)){
      printf("The binary tree is symmetric around its center");
    }else{
      printf("The binary tree is not symmetric around its center");
  }
  return 0;
}

//Insert on the left node
struct Node* insertLeft(struct Node* root, int data){
  root->left=newNode(data);
  return root->left;
}

//Insert on the right node
struct Node* insertRight(struct Node* root, int data){
  root->right=newNode(data);
  return root->right;
}

//Function to create a new binary tree from a given data
struct Node* newNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}

//Function to determine if the tree is symmetric
bool isSymmetric(struct Node* root){
  if(root == NULL){
    return true;
  }
  return isSymmetricalCheck(root->right, root->left);
}
//Function to compare the left node and the right node
bool isSymmetricalCheck(struct Node* rootRight, struct Node* rootLeft){
  if(rootRight == NULL && rootLeft == NULL){
    return true;
  }
  if(rootRight && rootLeft && rootRight->data == rootLeft->data){
    return isSymmetricalCheck(rootRight->left, rootLeft->right) && isSymmetricalCheck(rootRight->right, rootLeft->left);
  }

  return false;
}
