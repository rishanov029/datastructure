#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;

	printf("Enter the size of the first array: ");
	if (scanf("%d", &n) != 1 || n < 0) {
		fprintf(stderr, "Invalid array size.\n");
		return 1;
	}

	printf("Enter the size of the second array: ");
	if (scanf("%d", &m) != 1 || m < 0) {
		fprintf(stderr, "Invalid array size.\n");
		return 1;
	}

	int *first = malloc((size_t)n * sizeof(*first));
	int *second = malloc((size_t)m * sizeof(*second));
	int *merged = malloc((size_t)(n + m) * sizeof(*merged));

	if ((n > 0 && first == NULL) || (m > 0 && second == NULL) ||
		(n + m > 0 && merged == NULL)) {
		fprintf(stderr, "Memory allocation failed.\n");
		free(first);
		free(second);
		free(merged);
		return 1;
	}

	printf("Enter %d elements of the first sorted array: ", n);
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &first[i]) != 1) {
			fprintf(stderr, "Invalid input.\n");
			free(first);
			free(second);
			free(merged);
			return 1;
		}
	}

	printf("Enter %d elements of the second sorted array: ", m);
	for (int i = 0; i < m; ++i) {
		if (scanf("%d", &second[i]) != 1) {
			fprintf(stderr, "Invalid input.\n");
			free(first);
			free(second);
			free(merged);
			return 1;
		}
	}

	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (first[i] <= second[j]) {
			merged[k++] = first[i++];
		} else {
			merged[k++] = second[j++];
		}
	}
	while (i < n) {
		merged[k++] = first[i++];
	}
	while (j < m) {
		merged[k++] = second[j++];
	}

	printf("Merged sorted array: ");
	for (int index = 0; index < n + m; ++index) {
		printf("%d%s", merged[index], index == n + m - 1 ? "\n" : " ");
	}
	if (n + m == 0) {
		putchar('\n');
	}

	free(first);
	free(second);
	free(merged);
	return 0;
}
