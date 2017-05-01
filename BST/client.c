#include <stdio.h>
#include <stdlib.h>
#include "Visualize.h"
#include "BST.h"

int main() {
	Tree *root = NULL;
	insertNode(&root, 4);
	insertNode(&root, 6);
	insertNode(&root, 5);
	insertNode(&root, 8);
	insertNode(&root, 7);
	insertNode(&root, 9);
	insertNode(&root, 10);

	printf("Before balance:\n");
	print_ascii_tree(root);

	Tree *ref_f = findNode(root, 6);
	Tree *ref_p = parent(root, ref_f);
	Tree *ref_b = ref_f->right;
	Tree *ref_BL = ref_b->left;

	ref_b->left = ref_f;
	ref_p->right = ref_b;
	ref_f->right = ref_BL;


	printf("After balance:\n");
	print_ascii_tree(root);

	return 0;
}