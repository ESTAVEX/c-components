#include <stdio.h>
#include <stdlib.h>

struct node_st {
	int data;
	struct node_st *pleft;
	struct node_st *pright;
};

struct queue_st {
	struct node_st *pnode;
	struct node_st *pnext;
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

void enqueue(struct queue_st **front, struct queue_st **rear, struct node_st *node) {
	struct queue_st *newNode = malloc(sizeof(struct queue_st));
	newNode->pnode = node;
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

struct node_st *is_empty(struct queue_st *queue) {
	if (queue == NULL)
		return NULL;

	struct node_st *node = queue->pnode;

	if (node == NULL)
		return NULL;
	else
		return node;
}

// Just so we can print the tree on the screen
void get_level(struct node_st *root) {
	if (root == NULL)
		return;

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

struct node_st *get_min(struct node_st *root) {
	while (root->pleft != NULL) root = root->pleft;
	return root;
}

struct node_st *delete_node(struct node_st *root, int data) {
	if (root == NULL) {
		return root;
	} else if (data < root->data) {
		root->pleft = delete_node(root->pleft, data);
	} else if (data > root->data) {
		root->pright = delete_node(root->pright, data);
	} else { // FOUND IT! get rekt
		// case 1: no children
		if (root->pleft == NULL && root->pright == NULL) {
			free(root);
			root = NULL;
		}

		// case 2: no left child
		else if (root->pleft == NULL) {
			struct node_st *temp = root;
			root = root->pright;
			free(temp);
		}

		// case 3: no right child
		else if (root->pright == NULL) {
			struct node_st *temp = root;
			root = root->pleft;
			free(temp);
		}

		// case 4: two children
		else {
			struct node_st *temp = get_min(root->pright);
			root->data = temp->data;
			root->pright = delete_node(root->pright, temp->data);
		}
	}

	return root;
}

int main()
{
	struct node_st *root = NULL;
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 7);
	root = insert(root, 15);
	root = insert(root, 25);
	root = insert(root, 14);
	root = insert(root, 17);
	root = insert(root, 19);
	root = delete_node(root, 15);
	get_level(root);

	return 0;
}