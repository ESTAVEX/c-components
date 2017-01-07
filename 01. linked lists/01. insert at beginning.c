#include <stdio.h>
#include <stdlib.h>

struct node_st {
	int data;
	struct node_st *pnext;
};

void insert_at_beginning(struct node_st **head, int value) {
	struct node_st *temp = malloc(sizeof(struct node_st));
	temp->data = value;
	temp->pnext = NULL;

	if (*head == NULL) {
		*head = temp;
	} else {
		temp->pnext = *head;
		*head = temp;
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
	struct node_st *head = NULL;

	int n;
	printf("How many numbers?\n");
	scanf("%d", &n);

	int i, x;
	for (i = 0; i < n; i++) {
		printf("Enter a number: ");
		scanf("%d", &x);

		insert_at_beginning(&head, x);
		print(head);
	}

	return 0;
}