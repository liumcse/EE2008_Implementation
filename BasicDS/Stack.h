#ifndef STACK_H_
#define STACK_H_
#include "LinkedList.h"

typedef struct Stack {
	LinkedList ll;
} Stack;

int emptyStack(Stack *s);
int pushStack(Stack *s, int item);
int popStack(Stack *s);
int topStack(Stack *s);

#endif