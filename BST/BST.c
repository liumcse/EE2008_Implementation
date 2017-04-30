#include <stdio.h>
#include "BST.h"

void insertNode(Tree **node, int data) {
	Tree *temp = malloc(sizeof(Tree));
	temp->item = data;
	temp->left = NULL;
	temp->right = NULL;

	if (*node == NULL) {
		*node = temp;
		return;
	}

	if ((*node)->item > data) insertNode(&((*node)->left), data);
	else if((*node)->item < data) insertNode(&((*node)->right), data);
	else {
		printf("Duplicates\n");
      	return;
	}
}

Tree *findNode(Tree *node, int data) {
	if (node == NULL) return NULL;
	if (node->item == data) return node;
	if (node->item > data) 
		return findNode(node->left, data);
	else 
		return findNode(node->right, data);
}

void deleteNode(Tree *node, int data) {
	// 这个懒得写...
}

Tree *parent(Tree *root, Tree *node) {
	if (root->item == node->item || root == NULL) return NULL;
	if (root->left != NULL && root->left->item == node->item) return root;
	if (root->right != NULL && root->right->item == node->item) return root;
	if (node->item > root->item) return parent(root->right, node);
	if (node->item < root->item) return parent(root->left, node);
	return NULL;
}

void preorder(Tree *node) {
	if (node == NULL) return;
	printf("%d ", node->item);
	preorder(node->left);
	preorder(node->right);
}

void inorder(Tree *node) {
	if (node == NULL) return;
	inorder(node->left);
	printf("%d ", node->item);
	inorder(node->right);
}

void postorder(Tree *node) {
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->item);
}