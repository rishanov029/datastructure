#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

static Node *head = NULL;

static Node *create_node(int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if (node == NULL) {
		printf("Memory allocation failed.\n");
		return NULL;
	}
	node->data = value;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

static void insert_front(int value)
{
	Node *node = create_node(value);
	if (node == NULL) return;
	node->next = head;
	if (head != NULL) head->prev = node;
	head = node;
}

static void insert_back(int value)
{
	Node *node = create_node(value);
	if (node == NULL) return;
	if (head == NULL) {
		head = node;
		return;
	}
	Node *tail = head;
	while (tail->next != NULL) tail = tail->next;
	tail->next = node;
	node->prev = tail;
}

static void insert_at_position(int value, int position)
{
	Node *current = head;
	Node *node;
	int index;

	if (position < 1) {
		printf("Invalid position. Positions start at 1.\n");
		return;
	}
	if (position == 1) {
		insert_front(value);
		return;
	}

	for (index = 1; index < position - 1 && current != NULL; index++)
		current = current->next;
	if (current == NULL) {
		printf("Invalid position.\n");
		return;
	}

	node = create_node(value);
	if (node == NULL) return;
	node->prev = current;
	node->next = current->next;
	if (current->next != NULL) current->next->prev = node;
	current->next = node;
}

static void delete_value(int value)
{
	Node *current = head;
	while (current != NULL && current->data != value)
		current = current->next;

	if (current == NULL) {
		printf("Value not found.\n");
		return;
	}
	if (current->prev != NULL) current->prev->next = current->next;
	else head = current->next;
	if (current->next != NULL) current->next->prev = current->prev;
	free(current);
	printf("Node deleted.\n");
}

static void display_forward(void)
{
	Node *current = head;
	if (current == NULL) {
		printf("List is empty.\n");
		return;
	}
	printf("Forward: ");
	while (current != NULL) {
		printf("%d", current->data);
		if (current->next != NULL) printf(" <-> ");
		current = current->next;
	}
	printf("\n");
}

static void display_backward(void)
{
	Node *current = head;
	if (current == NULL) {
		printf("List is empty.\n");
		return;
	}
	while (current->next != NULL) current = current->next;
	printf("Backward: ");
	while (current != NULL) {
		printf("%d", current->data);
		if (current->prev != NULL) printf(" <-> ");
		current = current->prev;
	}
	printf("\n");
}

static void free_list(void)
{
	while (head != NULL) {
		Node *next = head->next;
		free(head);
		head = next;
	}
}

int main(void)
{
	int choice, value, position;

	do {
		printf("\nDoubly Linked List\n");
		printf("1. Insert at beginning\n2. Insert at end\n");
		printf("3. Insert at position\n4. Delete a value\n");
		printf("5. Display forward\n6. Display backward\n0. Exit\nChoice: ");
		if (scanf("%d", &choice) != 1) {
			printf("Invalid input.\n");
			free_list();
			return 1;
		}

		switch (choice) {
		case 1:
			printf("Enter value: ");
			if (scanf("%d", &value) != 1) { free_list(); return 1; }
			insert_front(value);
			break;
		case 2:
			printf("Enter value: ");
			if (scanf("%d", &value) != 1) { free_list(); return 1; }
			insert_back(value);
			break;
		case 3:
			printf("Enter value: ");
			if (scanf("%d", &value) != 1) { free_list(); return 1; }
			printf("Enter position (starting at 1): ");
			if (scanf("%d", &position) != 1) { free_list(); return 1; }
			insert_at_position(value, position);
			break;
		case 4:
			printf("Enter value to delete: ");
			if (scanf("%d", &value) != 1) { free_list(); return 1; }
			delete_value(value);
			break;
		case 5:
			display_forward();
			break;
		case 6:
			display_backward();
			break;
		case 0:
			break;
		default:
			printf("Invalid choice.\n");
		}
	} while (choice != 0);

	free_list();
	return 0;
}
