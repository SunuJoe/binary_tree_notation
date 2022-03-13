// Basic_Func_LinkedStack.c //

#include <stdio.h>
#include "Basic_LinkedStack.h"
#include <stdlib.h>

void O_Init(STACK1* pstack)
{
  pstack->top = NULL;
}

int O_S_isEmpty(STACK1* pstack)
{
  if(pstack->top == NULL)
    return TRUE;
  else
    return FALSE;
}

void O_Push(STACK1* pstack, Origin_data data)
{
  Origin_Stack_Node* newNode = (Origin_Stack_Node*)malloc(sizeof(Origin_Stack_Node));
  newNode->data = data;
  
  newNode->next = pstack->top;
  pstack->top = newNode;
}

Origin_data O_Pop(STACK1* pstack)
{
  if(O_S_isEmpty(pstack))
    exit(-1);
  else
  {
    Origin_Stack_Node* Temp = pstack->top;
    Origin_data temp_data = pstack->top->data;

    pstack->top = pstack->top->next;
    free(Temp);
    return temp_data;
  }
}

Origin_data O_Peek(STACK1* pstack)
{
  if(O_S_isEmpty(pstack))
    exit(-1);
  else
    return pstack->top->data;
}

