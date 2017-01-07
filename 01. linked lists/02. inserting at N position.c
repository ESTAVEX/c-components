#include <stdio.h>
#include <stdlib.h>

struct node_st {
	int data;
	struct node_st *pnext;
};

void insert_at(struct node_st **head, int value, int index) {
	struct node_st *temp = malloc(sizeof(struct node_st));
	temp->data = value;
	temp->pnext = NULL;

	if (index == 0) {
		temp->pnext = *head;
		*head = temp;
	} else {
		struct node_st *current = *head;

		int i;
		for (i = 0; i < index - 1; i++) {
			current = current->pnext;
		}

		temp->pnext = current->pnext;
		current->pnext = temp;
	}
}

void print(struct node_st *head) {
	struct node_st *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->pnext;
	}
	putchar('\n');
}

int main()
{
	struct node_st *list = NULL;
	insert_at(&list, 2, 0); // list: 2
	insert_at(&list, 3, 1); // list: 2 3
	insert_at(&list, 4, 0); // list: 4 2 3
	insert_at(&list, 5, 1); // list: 4 5 2 3
	print(list);

	return 0;
}