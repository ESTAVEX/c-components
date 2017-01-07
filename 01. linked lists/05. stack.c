#include <stdio.h>
#include <stdlib.h>

struct node_st {
	int data;
	struct node_st *pnext;
};

void push(struct node_st **head, int data) {
	struct node_st *newNode = malloc(sizeof(struct node_st));
	newNode->data = data;
	newNode->pnext = *head;
	*head = newNode;
}

void pop(struct node_st **head) {
	if (*head == NULL)
		return;

	struct node_st *temp = *head;
	*head = (*head)->pnext;
	free(temp);
}

void print(struct node_st *list) {
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->pnext;
	}
	putchar('\n');
}

int main()
{
	struct node_st *list = NULL;
	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	push(&list, 4);
	pop(&list);
	pop(&list);
	print(list); // output: 2 1

	return 0;
}