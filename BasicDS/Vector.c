#include "Vector.h"

int elemAtRank(Vector *v, int r) {
	if (findNode(&(v->ll), r) == NULL) return -1;
	return (findNode(&(v->ll), r))->item;
}

int removeAtRank(Vector *v, int r) {
	removeNode(&(v->ll), r);
	return 0;
}

int insertAtRank(Vector *v, int r, int item) {
	if (insertNode(&(v->ll), r, item) != -1)
		return 0;
	else 
		return -1;
}

int replaceAtRank(Vector *v, int r, int data) {
	if (findNode(&(v->ll), r) == NULL) return -1;
	ListNode *node = findNode(&(v->ll), r);
	node->item = data;
	return 0;
}