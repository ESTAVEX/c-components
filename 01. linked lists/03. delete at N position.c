#include <stdio.h>
#include <stdlib.h>

struct node_st {
	int data;
	struct node_st *pnext;
};

struct node_st *get_new_node(int data) {
	struct node_st *newNode = malloc(sizeof(struct node_st));
	newNode->data = data;
	newNode->pnext = NULL;
	return newNode;
}

void insert_on_end(struct node_st **head, int data) {
	if (*head == NULL) {
		*head = get_new_node(data);
	} else {
		struct node_st *current = *head;
		
		while (current->pnext != NULL)
			current = current->pnext;

		current->pnext = get_new_node(data);
	}
}

void print(struct node_st *head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->pnext;
	}
	putchar('\n');
}

void delete_at(struct node_st **head, int target) {
	struct node_st *temp = *head;

	if (target == 1) {
		*head = temp->pnext;
		free(temp);
		return;
	}

	int i;
	for (i = 0; i < target - 2; i++)
		temp = temp->pnext;

	struct node_st *current = temp->pnext;
	temp->pnext = current->pnext;
	free(current);
}

int main()
{
	struct node_st *list = NULL;
	insert_on_end(&list, 2); // 2
	insert_on_end(&list, 4); // 2 4
	insert_on_end(&list, 6); // 2 4 6
	insert_on_end(&list, 5); // 2 4 6 5
	print(list);

	int n;
	printf("Enter a position: ");
	scanf_s("%d", &n);

	delete_at(&list, n);
	print(list);

	return 0;
}