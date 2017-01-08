#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_st {
	char data;
	struct node_st *pnext;
};

void push(struct node_st **top, char c) {
	struct node_st *newNode = malloc(sizeof(struct node_st));
	newNode->data = c;
	newNode->pnext = *top;
	*top = newNode;
}

char pop(struct node_st **top) {
	if (*top == NULL)
		return;

	char c = (*top)->data;
	struct node_st *temp = *top;
	*top = (*top)->pnext;
	free(temp);

	return c;
}

void reverse(struct node_st *top, char *s, int n) {
	int i;
	for (i = 0; i < n; i++)
		push(&top, s[i]);

	for (i = 0; i < n; i++)
		s[i] = pop(&top);
}

int main()
{
	char str[21];
	struct node_st *list = NULL;
	printf("Enter a string: ");
	gets(str);
	reverse(list, str, strlen(str));
	printf("Reversed string: %s\n", str);

	return 0;
}