#ifndef PRIORITYQUEUE_H_H
#define PRIORITYQUEUE_H_H
#include <stdlib.h>

int Qsize();
int isEmpty();
void insertItem(int key_, int value_);
int minElement();
int minKey();
int removeMin();

#endif