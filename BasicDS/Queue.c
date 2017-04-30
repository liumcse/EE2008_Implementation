#include <stdio.h>
#include "Queue.h"

int emptyQueue(Queue *q) {
	if ((q->ll).size == 0) return 1;
	else return 0;
}

int enqueue(Queue *q, int item) {
	insertNode(&(q->ll), (q->ll).size, item);
}

int dequeue(Queue *q) {
	int item = ((q->ll).head)->item;
	removeNode(&(q->ll), 0);
	return item;
}

int front(Queue *q) {
	return ((q->ll).head)->item;
}