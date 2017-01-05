#include <stdio.h>
#include <stdlib.h>

// To get a level order, we need to create
// a custom queue list.

struct node_st {
	int data;
	struct node_st *pleft;
	struct node_st *pright;
};

struct queue_st {
	struct node_st *pnode;
	struct queue_st *pnext;
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

void enqueue(struct queue_st **front, struct queue_st **rear, struct node_st *root) {
	struct queue_st *newNode = malloc(sizeof(struct queue_st));
	newNode->pnode = root;
	newNode->pnext = NULL;

	if (*front == NULL && *rear == NULL) {
		*front = newNode;
		*rear = newNode;
		return;
	}

	(*rear)->pnext = newNode;
	*rear = newNode;
}

void dequeue(struct queue_st **front, struct queue_st **rear) {
	struct queue_st *temp = *front;

	if (*front == NULL)
		return;

	if (*front == *rear) {
		*front = NULL;
		*rear = NULL;
	} else {
		*front = (*front)->pnext;
	}

	free(temp);
}

struct node_st *is_empty(struct queue_st *root) {
	if (root == NULL)
		return NULL;

	struct node_st *node = root->pnode;

	if (node == NULL)
		return NULL;
	else
		return node;
}

void level_order(struct node_st *root) {
	if (root == NULL) {
		return;
	}

	struct queue_st *front = NULL;
	struct queue_st *rear = NULL;
	enqueue(&front, &rear, root);

	while (is_empty(front) != NULL) {
		struct node_st *current = is_empty(front);
		printf("%d ", current->data);

		if (current->pleft != NULL)
			enqueue(&front, &rear, current->pleft);
		if (current->pright != NULL)
			enqueue(&front, &rear, current->pright);

		dequeue(&front, &rear);
	}

	putchar('\n');
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

	level_order(root);

	return 0;
}
