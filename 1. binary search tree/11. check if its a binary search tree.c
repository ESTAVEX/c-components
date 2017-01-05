#include <stdio.h>
#include <stdlib.h>

// A Binary Search Tree is when tree has proper elements inside.
// All elements less than their parent must go to the Left and
// all elements greater than their parent must go to the Right.
// If this is not met, then there's a violation of BST (binary
// search tree) rule, and in that case, it's just a Binary Tree.

struct node_st {
	int data;
	struct node_st *pleft;
	struct node_st *pright;
};

struct node_st *get_new_node(int value) {
	struct node_st *newNode = malloc(sizeof(struct node_st));
	newNode->data = value;
	newNode->pleft = NULL;
	newNode->pright = NULL;
	return newNode;
}

struct node_st *insert(struct node_st *root, int value) {
	if (root == NULL) {
		root = get_new_node(value);
	} else if (value <= root->data) {
		root->pleft = insert(root->pleft, value);
	} else {
		root->pright = insert(root->pright, value);
	}
	return root;
}

// bst = binary search tree
int is_bst_util(struct node_st *root, int minValue, int maxValue) {
	if (root == NULL)
		return 1;

	if (root->data > minValue && root->data < maxValue &&
		is_bst_util(root->pleft, minValue, root->data) &&
		is_bst_util(root->pright, root->data, maxValue)) {
		return 1;
	} else {
		return 0;
	}
}

int is_binary_search_tree(struct node_st *root) {
	return is_bst_util(root, INT_MIN, INT_MAX); // INT_MIN and INT_MAX are macros
}

int main()
{
	struct node_st *root = NULL;
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 7);
	root = insert(root, 15);
	root = insert(root, 14);
	root = insert(root, 17);
	root = insert(root, 19);

	printf("is this a binary search tree?\n");
	if (is_binary_search_tree(root))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
