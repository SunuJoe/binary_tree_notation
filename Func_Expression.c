// Func_Expression.c //

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedStack.h"
#include "Expression.h"

TREE* makeExpTree(char* str)
{
  STACK stack;
  Init(&stack);

  int len, i;
  char val;
  len = strlen(str);

  TREE* root;

  for(i=0; i<len; i++)
  {
    val = str[i];
    root = makeNode();
    
    if(isdigit(val))
    {
      setData(root, val - '0');
    }
    else
    {
      setData(root, val);
      makeRightSubTree(root, Pop(&stack)); 
      makeLeftSubTree(root, Pop(&stack));
    }
    Push(&stack, root);
  }
  return root;
}

int Calc_Result(TREE* root)
{
  int op1, op2;
  
  if((root->left == NULL) && (root->right == NULL))
    return getData(root);

  op1 = Calc_Result(root->left);
  op2 = Calc_Result(root->right);

  switch(getData(root))
  {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1*op2;
    case '/':
      return op1/op2;
  }

  return -1;
}

void Func_show(int data)
{
  if(0<=data && data<=9)
    printf("%d", data);
  else
    printf("%c", data);
}

void ShowPrefix(TREE* root)
{
  printf("Prefix Notation : ");
  PreorderTraversal(root, Func_show);
}

void ShowInfix(TREE* root)
{
  printf("Infix Notation : ");
  InorderTraversal(root, Func_show);
}

void ShowPostfix(TREE* root)
{
  printf("Postfix Notation : ");
  PostorderTraversal(root, Func_show);
}

