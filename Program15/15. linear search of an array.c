#include <stdio.h>

int main(void)
{
	int n, key, found = 0;

	printf("Enter the number of elements: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid array size.\n");
		return 1;
	}

	int array[n];

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &array[i]) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
	}

	printf("Enter the element to search for: ");
	if (scanf("%d", &key) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (array[i] == key) {
			printf("Element found at position %d.\n", i + 1);
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("Element not found.\n");
	}

	return 0;
}
