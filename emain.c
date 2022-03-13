// emain.c //
// gcc emain.c Func_Basic_LinkedStack.c Func_LinkedStack.c Func_Postfix.c
// Func_BinaryTree.c Func_Expression.c -o emain

#include <stdio.h>
#include <string.h>
#include "Postfix.h"
#include "Expression.h"

int main(int argc, char* argv[])
{
  char str0[20];
  char str1[20];

  printf("Enter your notation : ");
  scanf("%s", str1);
  strcpy(str0, str1);

  infix_to_postfix(str1);

  TREE* root = makeExpTree(str1);

  //int data = getData(root);
  //printf("%c\n", data);

  int result;
  result = Calc_Result(root);
  
  printf("Arithmatic Result : %d\n", result);

  printf("\n");
  printf("Your input noation : %s\n", str0);

  ShowPrefix(root);
  printf("\n");
  printf("Infix Noatation : ");
  ShowInfix(root);
  printf("\n");
  ShowPostfix(root);
  printf("\n");
  return 0;
}
