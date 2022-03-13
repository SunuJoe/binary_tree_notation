// Func_BinaryTree.c //

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

TREE* makeNode(void)
{
  TREE* newNode = (TREE*)malloc(sizeof(TREE));
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void setData(TREE* root, B_data data)
{
  root->data = data;
}

B_data getData(TREE* root)
{
  return root->data;
}

TREE* getLeftSubTree(TREE* root)
{
  return root->left;
}

TREE* getRightSubTree(TREE* root)
{
  return root->right;
}

void makeLeftSubTree(TREE* root, TREE* sub)
{
  root->left = sub;
}

void makeRightSubTree(TREE* root, TREE* sub)
{
  root->right = sub;
}

void PreorderTraversal(TREE* root, Func_React action)
{
  if(root == NULL)
    return;
  
  action(root->data);
  PreorderTraversal(root->left, action);
  PreorderTraversal(root->right, action);
}

void InorderTraversal(TREE* root, Func_React action)
{
  if(root == NULL)
    return;
  
  InorderTraversal(root->left, action);
  action(root->data);
  InorderTraversal(root->right, action);
}

void PostorderTraversal(TREE* root, Func_React action)
{
  if(root == NULL)
    return;
  
  PostorderTraversal(root->left, action);
  PostorderTraversal(root->right, action);
  action(root->data);
}





