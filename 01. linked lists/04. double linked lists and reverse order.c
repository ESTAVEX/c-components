#include <stdio.h>
#include <stdlib.h>

struct node_st {
	int data;
	struct node_st *pnext;
	struct node_st *pprev;
};

struct node_st *get_new_node(int value) {
	struct node_st *newNode = malloc(sizeof(struct node_st));
	newNode->data = value;
	newNode->pprev = NULL;
	newNode->pnext = NULL;
	return newNode;
}

void insert_on_start(struct node_st **head, int value) {
	struct node_st *newNode = get_new_node(value);

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	(*head)->pprev = newNode;
	newNode->pnext = *head;
	*head = newNode;
}

void print(struct node_st *head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->pnext;
	}
	putchar('\n');
}

void reverse_print(struct node_st *head) {
	struct node_st *temp = head;
	if (temp == NULL)
		return;

	while (temp->pnext != NULL)
		temp = temp->pnext;
	
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->pprev;
	}

	putchar('\n');
}

int main()
{
	struct node_st *list = NULL;
	insert_on_start(&list, 1);
	insert_on_start(&list, 2);
	insert_on_start(&list, 3);
	insert_on_start(&list, 4);
	print(list);
	reverse_print(list);

	return 0;
}