// Func_Postfix.c //

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Basic_LinkedStack.h"

int op_priority(char op);
int op_comp(char op1, char op2);

void infix_to_postfix(char* str)
{
  STACK1 stack;
  O_Init(&stack);
  int len, i;
  int idx = 0; 
  Origin_data val, pop_val;
  len = strlen(str);

  char* convstr = (char*)malloc(len+1);
  memset(convstr, 0, sizeof(char)*len+1);

  for(i=0; i<len; i++)
  {
    val = str[i];
    if(isdigit(val))
    {
      convstr[idx++] = val;
    }
    else
    {
      switch(val)
      {
        case '(':
          O_Push(&stack, val);
          break;
        case ')':
        {
          while(1)
          {
            pop_val = O_Pop(&stack);
            if(pop_val == '(')
              break;
            convstr[idx++] = pop_val;
          }
          break;
        }
        case '+': case '-':
        case '*': case '/':
        {
          while((!O_S_isEmpty(&stack)) && (op_comp(O_Peek(&stack), val) >= 0))
          {
            convstr[idx++] = O_Pop(&stack);
          }
          O_Push(&stack, val);
          break;
        }
        break;
      }
    }
  }
  while(!O_S_isEmpty(&stack))
  {
    convstr[idx++] = O_Pop(&stack);
  }
  
  strcpy(str, convstr);
  free(convstr);
}

int op_priority(char op)
{
  switch(op)
  {
    case '(':
      return 1;
    case '+': case '-':
      return 3;
    case '*': case '/':
      return 5;
  }
  return -1;
}

int op_comp(char op1, char op2)
{
  int comp1 = op_priority(op1);
  int comp2 = op_priority(op2);

  if(comp1>comp2)
    return 1;
  else if(comp1<comp2)
    return -1;
  else
    return 0;
}




