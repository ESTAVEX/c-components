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

int get_level(struct node_st *root, int data, int level) {
	if (root == NULL)
		return -1;

	if (data == root->data)
		return level;

	if (data < root->data)
		return get_level(root->pleft, data, ++level);
	else
		return get_level(root->pright, data, ++level);
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
	printf("Enter a target number: ");
	scanf("%d", &num);

	printf("%d is on level %d\n", num, get_level(root, num, 0));

	return 0;
}
