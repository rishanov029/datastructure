#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter the number of elements: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	int numbers[n];
	printf("Enter %d numbers: ", n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &numbers[i]) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (numbers[j] > numbers[j + 1]) {
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}

	printf("Numbers in ascending order: ");
	for (int i = 0; i < n; i++) {
		printf("%d%s", numbers[i], i == n - 1 ? "\n" : " ");
	}

	return 0;
}
