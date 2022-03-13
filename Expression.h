// Expression.h //

#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include "BinaryTree.h"

TREE* makeExpTree(char* str);

int Calc_Result(TREE* root);

void ShowPrefix(TREE* root);
void ShowInfix(TREE* root);
void ShowPostfix(TREE* root);

#endif

