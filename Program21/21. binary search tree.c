/* Binary search tree: insertion, search, deletion, and traversals. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

static Node *create_node(int value)
{
	Node *node = (Node *)malloc(sizeof(*node));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

static Node *insert(Node *root, int value)
{
	if (root == NULL)
		return create_node(value);
	if (value < root->data)
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);
	else
		printf("Duplicate values are not inserted.\n");
	return root;
}

static Node *search(Node *root, int value)
{
	while (root != NULL && root->data != value)
		root = (value < root->data) ? root->left : root->right;
	return root;
}

static Node *minimum_node(Node *root)
{
	while (root != NULL && root->left != NULL)
		root = root->left;
	return root;
}

static Node *delete_node(Node *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->data) {
		root->left = delete_node(root->left, value);
	} else if (value > root->data) {
		root->right = delete_node(root->right, value);
	} else {
		if (root->left == NULL) {
			Node *right = root->right;
			free(root);
			return right;
		}
		if (root->right == NULL) {
			Node *left = root->left;
			free(root);
			return left;
		}

		Node *successor = minimum_node(root->right);
		root->data = successor->data;
		root->right = delete_node(root->right, successor->data);
	}
	return root;
}

static void inorder(const Node *root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

static void preorder(const Node *root)
{
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

static void postorder(const Node *root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

static void free_tree(Node *root)
{
	if (root != NULL) {
		free_tree(root->left);
		free_tree(root->right);
		free(root);
	}
}

int main(void)
{
	Node *root = NULL;
	int choice, value;

	for (;;) {
		printf("\n--- Binary Search Tree ---\n"
			   "1. Insert\n2. Search\n3. Delete\n"
			   "4. Inorder\n5. Preorder\n6. Postorder\n0. Exit\n"
			   "Choice: ");
		if (scanf("%d", &choice) != 1) {
			printf("Invalid input.\n");
			break;
		}

		switch (choice) {
		case 1:
			printf("Value to insert: ");
			if (scanf("%d", &value) != 1)
				goto done;
			root = insert(root, value);
			break;
		case 2:
			printf("Value to search: ");
			if (scanf("%d", &value) != 1)
				goto done;
			printf(search(root, value) ? "Value found.\n" : "Value not found.\n");
			break;
		case 3:
			printf("Value to delete: ");
			if (scanf("%d", &value) != 1)
				goto done;
			if (search(root, value) == NULL)
				printf("Value not found.\n");
			else {
				root = delete_node(root, value);
				printf("Value deleted.\n");
			}
			break;
		case 4:
			printf("Inorder: ");
			inorder(root);
			putchar('\n');
			break;
		case 5:
			printf("Preorder: ");
			preorder(root);
			putchar('\n');
			break;
		case 6:
			printf("Postorder: ");
			postorder(root);
			putchar('\n');
			break;
		case 0:
			goto done;
		default:
			printf("Invalid choice.\n");
		}
	}

done:
	free_tree(root);
	return 0;
}
