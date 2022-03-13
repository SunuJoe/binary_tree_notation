// LinkedStack.h //
// modified Linked Stack for Tree calculator. //

#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0
/*
typedef int origin_data; // using just stack.

typedef struct __origin_node
{
  origin_data data;
  struct __base_node* next;
} Origin_Stack_Node;

typedef struct __origin_linkedstack
{
  Origin_Stack_Node* top;
} Origin_LinkedStack;

typedef Origin_LinkedStack O_STACK;  // origin STACK;
*/
typedef TREE* S_data;

typedef struct __stack_node
{
  S_data data;
  struct __stack_node* next;
} Stack_Node;

typedef struct __linkedstack
{
  Stack_Node* top;
} LinkedStack;

typedef LinkedStack STACK;

void Init(STACK* pstack);

int S_isEmpty(STACK* pstack);
void Push(STACK* pstack, S_data data);

S_data Pop(STACK* pstack);
S_data Peek(STACK* pstack);

#endif


