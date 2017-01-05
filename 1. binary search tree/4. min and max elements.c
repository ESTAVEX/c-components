#include <stdio.h>
#include <stdlib.h>

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

int find_min(struct node_st *root) {
	if (root == NULL) {
		printf("Can't find min - tree is empty\n");
		return -1;
	} else if (root->pleft == NULL) {
		return root->data;
	}
	return find_min(root->pleft);
}

int find_max(struct node_st *root) {
	if (root == NULL) {
		printf("Can't find max - tree is empty\n");
		return -1;
	} else if (root->pright == NULL) {
		return root->data;
	}
	return find_max(root->pright);
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

	printf("min: %d\nmax: %d\n", find_min(root), find_max(root));

	return 0;
}
