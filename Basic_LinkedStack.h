// Basic_LinkedStack.h //


#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

//#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0

typedef int Origin_data; // using just stack.
//typedef TREE* S_data;

typedef struct __origin_stack_node
{
  Origin_data data;
  struct __origin_stack_node* next;
} Origin_Stack_Node;

typedef struct __Origin_linkedstack
{
  Origin_Stack_Node* top;
} Origin_LinkedStack;

typedef Origin_LinkedStack STACK1;

void O_Init(STACK1* pstack);

int O_S_isEmpty(STACK1* pstack);
void O_Push(STACK1* pstack, Origin_data data);

Origin_data O_Pop(STACK1* pstack);
Origin_data O_Peek(STACK1* pstack);

#endif


