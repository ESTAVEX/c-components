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

int search_tree(struct node_st *root, int target) {
	if (root == NULL) {
		return 0;
	} else if (target == root->data) {
		return 1;
	} else if (target < root->data) {
		return search_tree(root->pleft, target);
	} else {
		return search_tree(root->pright, target);
	}
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

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	if (search_tree(root, num) == 1)
		printf("Found!\n");
	else
		printf("Not found\n");

	return 0;
}
