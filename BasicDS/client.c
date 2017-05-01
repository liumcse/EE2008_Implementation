#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"

int main() {

	printf("////////////// Linked List //////////////\n\n");

    LinkedList ll;
    ll.head = NULL;
    ll.size = 0;
    
    printf("Insert 1 at 0: ");
    insertNode(&ll, 0, 1);
    printList(&ll);
    printf("\nInsert 2 at 1: ");
    insertNode(&ll, 1, 2);
    printList(&ll);
    printf("\nInsert 3 at 2: ");
    insertNode(&ll, 2, 3);
    printList(&ll);
    printf("\nInsert 4 at 3: ");
    insertNode(&ll, 3, 4);
    printList(&ll);
    printf("\nInsert 5 at 1: ");
    insertNode(&ll, 1, 5);
    printList(&ll);

    printf("\n\nRemove index 4: ");
    removeNode(&ll, 4);
    printList(&ll);
    printf("\nRemove index 3: ");
    removeNode(&ll, 3);
    printList(&ll);
    printf("\nRemove index 2: ");
    removeNode(&ll, 2);
    printList(&ll);
    printf("\nRemove index 1: ");
    removeNode(&ll, 1);
    printList(&ll);
    printf("\nRemove index 0: ");
    removeNode(&ll, 0);
    printList(&ll);

    printf("\n\n////////////// Linked List //////////////\n");

    printf("\n////////////// Stack //////////////\n\n");

    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;

    printf("Push 5 to stack: ");
    pushStack(&s, 5);
    printList(&(s.ll));
    printf("\nPush 4 to stack: ");
    pushStack(&s, 4);
    printList(&(s.ll));
    printf("\nPush 3 to stack: ");
    pushStack(&s, 3);
    printList(&(s.ll));
    printf("\nPush 2 to stack: ");
    pushStack(&s, 2);
    printList(&(s.ll));
    printf("\nPush 1 to stack: ");
    pushStack(&s, 1);
    printList(&(s.ll));

    printf("\n\nPop return %d: ", popStack(&s));
    printList(&(s.ll));
    printf("\nPop return %d: ", popStack(&s));
    printList(&(s.ll));
    printf("\nPop return %d: ", popStack(&s));
    printList(&(s.ll));
    printf("\nPop return %d: ", popStack(&s));
    printList(&(s.ll));
    printf("\nPop return %d: ", popStack(&s));
    printList(&(s.ll));

    printf("\n\n////////////// Stack //////////////\n\n");

    printf("\n////////////// Queue //////////////\n\n");

    Queue q;
    q.ll.head = NULL;
    q.ll.size = 0;

    printf("Enqueue 1 to queue: ");
    enqueue(&q, 1);
    printList(&(q.ll));
    printf("\nEnqueue 2 to queue: ");
    enqueue(&q, 2);
    printList(&(q.ll));
    printf("\nEnqueue 3 to queue: ");
    enqueue(&q, 3);
    printList(&(q.ll));
    printf("\nEnqueue 4 to queue: ");
    enqueue(&q, 4);
    printList(&(q.ll));
    printf("\nEnqueue 5 to queue: ");
    enqueue(&q, 5);
    printList(&(q.ll));

    printf("\n\nDequeue return %d: ", dequeue(&q));
    printList(&(q.ll));
    printf("\nDequeue return %d: ", dequeue(&q));
    printList(&(q.ll));
    printf("\nDequeue return %d: ", dequeue(&q));
    printList(&(q.ll));
    printf("\nDequeue return %d: ", dequeue(&q));
    printList(&(q.ll));
    printf("\nDequeue return %d: ", dequeue(&q));
    printList(&(q.ll));

    printf("\n\n////////////// Queue //////////////\n\n");

    printf("\n////////////// Vector //////////////\n\n");

    Vector v;
    v.ll.head = NULL;
    v.ll.size = 0;

    printf("Insert 5 at rank 0: ");
    insertAtRank(&v, 0, 5);
    printList(&(v.ll));
    printf("\nInsert 4 at rank 0: ");
    insertAtRank(&v, 0, 4);
    printList(&(v.ll));
    printf("\nInsert 3 at rank 0: ");
    insertAtRank(&v, 0, 3);
    printList(&(v.ll));
    printf("\nInsert 2 at rank 0: ");
    insertAtRank(&v, 0, 2);
    printList(&(v.ll));
    printf("\nInsert 1 at rank 0: ");
    insertAtRank(&v, 0, 1);
    printList(&(v.ll));

    printf("\n\nReplace with 100 at rank 4: ");
    replaceAtRank(&v, 4, 100);
    printList(&(v.ll));
    printf("\nReplace with 200 at rank 2: ");
    replaceAtRank(&v, 2, 200);
    printList(&(v.ll));

    printf("\n\nRemove at rank 3: ");
    removeAtRank(&v, 3);
    printList(&(v.ll));

    printf("\n\nElement at rank 3: %d", elemAtRank(&v, 3));
    printf("\n\nElement at rank 4: %d", elemAtRank(&v, 4));

    printf("\n\n////////////// Vector //////////////\n\n");

    return 0;
}