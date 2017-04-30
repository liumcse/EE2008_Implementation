#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct _ListNode {
	int item;
	struct _ListNode *next;
} ListNode;

typedef struct _LinkedList {
	int size;
	ListNode *head;
} LinkedList;

void printList(LinkedList *ll);
int insertNode(LinkedList *ll, int index, int data);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList *ll, int index);

#endif