#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

static void insert_at_beginning(Node **head, int value)
{
	Node *node = malloc(sizeof *node);
	if (node == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}
	node->data = value;
	node->next = *head;
	*head = node;
}

static void insert_at_end(Node **head, int value)
{
	Node *node = malloc(sizeof *node);
	Node *current;
	if (node == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}
	node->data = value;
	node->next = NULL;

	if (*head == NULL) {
		*head = node;
		return;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
}

static void delete_value(Node **head, int value)
{
	Node *current = *head;
	Node *previous = NULL;

	while (current != NULL && current->data != value) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		printf("Value not found.\n");
		return;
	}
	if (previous == NULL)
		*head = current->next;
	else
		previous->next = current->next;
	free(current);
	printf("Value deleted.\n");
}

static void display(const Node *head)
{
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	printf("List: ");
	while (head != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

static void free_list(Node *head)
{
	while (head != NULL) {
		Node *next = head->next;
		free(head);
		head = next;
	}
}

int main(void)
{
	Node *head = NULL;
	int choice, value;

	for (;;) {
		printf("\nSingly Linked List Menu\n"
			   "1. Insert at beginning\n"
			   "2. Insert at end\n"
			   "3. Delete a value\n"
			   "4. Display list\n"
			   "5. Exit\n"
			   "Enter choice: ");
		if (scanf("%d", &choice) != 1) {
			printf("Invalid input.\n");
			break;
		}

		switch (choice) {
		case 1:
			printf("Enter value: ");
			if (scanf("%d", &value) != 1)
				goto done;
			insert_at_beginning(&head, value);
			break;
		case 2:
			printf("Enter value: ");
			if (scanf("%d", &value) != 1)
				goto done;
			insert_at_end(&head, value);
			break;
		case 3:
			printf("Enter value to delete: ");
			if (scanf("%d", &value) != 1)
				goto done;
			delete_value(&head, value);
			break;
		case 4:
			display(head);
			break;
		case 5:
			goto done;
		default:
			printf("Invalid choice.\n");
		}
	}

done:
	free_list(head);
	return 0;
}
