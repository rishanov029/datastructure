#include <stdio.h>

int main(void)
{
	int size;

	printf("Enter the number of elements in the sorted array: ");
	if (scanf("%d", &size) != 1 || size <= 0) {
		printf("Invalid array size.\n");
		return 1;
	}

	int array[size];
	printf("Enter %d elements in ascending order: ", size);
	for (int i = 0; i < size; i++) {
		if (scanf("%d", &array[i]) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
	}

	int target;
	printf("Enter the value to search for: ");
	if (scanf("%d", &target) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	int low = 0;
	int high = size - 1;
	int found = -1;

	while (low <= high) {
		int middle = low + (high - low) / 2;

		if (array[middle] == target) {
			found = middle;
			break;
		} else if (array[middle] < target) {
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}

	if (found >= 0) {
		printf("Element found at index %d.\n", found);
	} else {
		printf("Element not found.\n");
	}

	return 0;
}
