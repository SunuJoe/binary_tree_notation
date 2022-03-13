// BinaryTree.h //

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef int B_data;

typedef struct __tree_node
{
  B_data data;
  struct __tree_node* left;
  struct __tree_node* right;
} TREE;

TREE* makeNode(void);

void setData(TREE* root, B_data data);
B_data getData(TREE* root);

TREE* getLeftSubTree(TREE* root);
TREE* getRightSubTree(TREE* root);

void makeLeftSubTree(TREE* root, TREE* sub);
void makeRightSubTree(TREE* root, TREE* sub);

typedef void (*Func_React)(B_data data);

void PreorderTraversal(TREE* root, Func_React action);
void InorderTraversal(TREE* root, Func_React action);
void PostorderTraversal(TREE* root, Func_React action);

#endif
