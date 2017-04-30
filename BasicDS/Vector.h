#ifndef VECTOR_H_
#define VECTOR_H_
#include "LinkedList.h"

typedef struct Vector {
	LinkedList ll;
} Vector;

int elemAtRank(Vector *v, int r);
int replaceAtRank(Vector *v, int r, int item);
int insertAtRank(Vector *v, int r, int item);
int removeAtRank(Vector *v, int r);

#endif