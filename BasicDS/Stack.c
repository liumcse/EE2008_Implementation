#include <stdio.h>
#include "Stack.h"

int emptyStack(Stack *s) {
	if ((s->ll).size == 0) return 1;
	else return 0;
}

int pushStack(Stack *s, int item) {
	insertNode(&(s->ll), 0, item);
}

int popStack(Stack *s) {
	int item = ((s->ll).head)->item;
	removeNode(&(s->ll), 0);
	return item;
}

int topStack(Stack *s) {
	return ((s->ll).head)->item;
}