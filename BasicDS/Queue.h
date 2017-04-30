#ifndef QUEUE_H_
#define QUEUE_H_
#include "LinkedList.h"

typedef struct Queue {
	LinkedList ll;
} Queue;

int emptyQueue(Queue *q);
int enqueue(Queue *q, int item);
int dequeue(Queue *q);
int front(Queue *q);

#endif