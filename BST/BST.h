#ifndef BST_H_
#define BST_H_
#include <stdlib.h>

typedef struct Tree {
	struct Tree *left;
	struct Tree *right;
	int item;
} Tree;

void insertNode(Tree **node, int data);
Tree *findNode(Tree *node, int data);
void deleteNode(Tree *node, int data);
Tree *parent(Tree *root, Tree *node);
void preorder(Tree *node);
void inorder(Tree *node);
void postorder(Tree *node);

#endif