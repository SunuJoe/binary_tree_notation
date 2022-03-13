// Func_LinkedStack.c //


#include <stdio.h>
#include "LinkedStack.h"
#include <stdlib.h>

void Init(STACK* pstack)
{
  pstack->top = NULL;
}

int S_isEmpty(STACK* pstack)
{
  if(pstack->top == NULL)
    return TRUE;
  else
    return FALSE;
}

void Push(STACK* pstack, S_data data)
{
  Stack_Node* newNode = (Stack_Node*)malloc(sizeof(Stack_Node));
  newNode->data = data;
  
  newNode->next = pstack->top;
  pstack->top = newNode;
}

S_data Pop(STACK* pstack)
{
  if(S_isEmpty(pstack))
    exit(-1);
  else
  {
    Stack_Node* Temp = pstack->top;
    S_data temp_data = pstack->top->data;

    pstack->top = pstack->top->next;
    free(Temp);
    return temp_data;
  }
}

S_data Peek(STACK* pstack)
{
  if(S_isEmpty(pstack))
    exit(-1);
  else
    return pstack->top->data;
}

