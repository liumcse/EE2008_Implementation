#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int insertNode(LinkedList *ll, int index, int data) {
	ListNode *pre, *cur;
	// If the list is NULL or index is invalid, return -1
	if (ll == NULL || index < 0 || index > ll->size + 1) return -1;

	// If the list is empty or index is 0, insert to beginning
	if (ll->head == NULL || index == 0) {
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = data;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as last node
	if (index == ll->size) {
		pre = findNode(ll, ll->size - 1);
		cur = malloc(sizeof(ListNode));
		cur->item = data;
		cur->next = NULL;
		pre->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as intermediate node
	else {
		pre = findNode(ll, index - 1);
		cur = malloc(sizeof(ListNode));
		cur->item = data;
		cur->next = pre->next;
		pre->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}

int removeNode(LinkedList *ll, int index) {
	ListNode *pre, *cur;

	// If list is empty, or invalid index
	if (ll->head == NULL || index < 0 || index >= ll->size) return -1;

	// If remove the head
	if (index == 0) {
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 0;
	}

	// If remove the tail
	if (index == ll->size - 1) {
		pre = findNode(ll, index - 1);
		cur = pre->next;
		pre->next = NULL;
		free(cur);
		ll->size--;
		return 0;
	}

	// Remove intermediate node
	else {
		pre = findNode(ll, index - 1);
		cur = pre->next;
		pre->next = pre->next->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;

}

ListNode * findNode(LinkedList *ll, int index) {
   	ListNode *temp;
   
   	if (ll == NULL || index < 0 || index >= ll->size)
    	return NULL;
   
   	temp = ll->head;
   
   	if (temp == NULL || index < 0)
      	return NULL;
   
   	while (index > 0){
      	temp = temp->next;
      	if (temp == NULL)
        	return NULL;
      	index--;
   	}
   
   	return temp;
}

void printList(LinkedList *ll) {

	ListNode *temp = ll->head;
   
	if (temp == NULL) {
		return;
	}
   	while (temp != NULL) {
    	printf("%d ", temp->item);
    	temp = temp->next;
   	}
}