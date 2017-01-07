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

void insert(struct node_st **root, int value) {
	if (*root == NULL) {
		*root = get_new_node(value);
	} else if (value <= (*root)->data) {
		insert(&((*root))->pleft, value);
	} else {
		insert(&((*root))->pright, value);
	}
}

int main()
{
	struct node_st *root = NULL;
	insert(&root, 20);
	insert(&root, 10);
	insert(&root, 30);
	insert(&root, 7);
	insert(&root, 15);
	insert(&root, 14);
	insert(&root, 17);
	insert(&root, 19);

	return 0;
}
