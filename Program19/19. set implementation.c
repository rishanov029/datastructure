#include <stdint.h>
#include <stdio.h>

#define UNIVERSE_SIZE 64

typedef uint64_t Set;

static int insert_element(Set *set, unsigned int element)
{
	if (element >= UNIVERSE_SIZE)
		return 0;
	*set |= UINT64_C(1) << element;
	return 1;
}

static Set set_union(Set a, Set b)
{
	return a | b;
}

static Set set_difference(Set a, Set b)
{
	return a & ~b;
}

static void display_set(Set set)
{
	int first = 1;
	printf("{");
	for (unsigned int element = 0; element < UNIVERSE_SIZE; ++element) {
		if (set & (UINT64_C(1) << element)) {
			printf("%s%u", first ? "" : ", ", element);
			first = 0;
		}
	}
	printf("}\n");
}

int main(void)
{
	Set a = 0, b = 0;
	int choice;

	for (;;) {
		printf("\n1. Insert into a set\n2. Union (A union B)\n"
			   "3. Difference (A - B)\n4. Display A and B\n5. Exit\n"
			   "Choice: ");
		if (scanf("%d", &choice) != 1)
			return 0;

		if (choice == 1) {
			int set_number;
			unsigned int element;
			printf("Set (1 for A, 2 for B): ");
			if (scanf("%d", &set_number) != 1)
				return 0;
			printf("Element (0-63): ");
			if (scanf("%u", &element) != 1)
				return 0;
			if (set_number == 1 && insert_element(&a, element))
				printf("Inserted into A.\n");
			else if (set_number == 2 && insert_element(&b, element))
				printf("Inserted into B.\n");
			else
				printf("Invalid set or element.\n");
		} else if (choice == 2) {
			printf("A union B = ");
			display_set(set_union(a, b));
		} else if (choice == 3) {
			printf("A - B = ");
			display_set(set_difference(a, b));
		} else if (choice == 4) {
			printf("A = ");
			display_set(a);
			printf("B = ");
			display_set(b);
		} else if (choice == 5) {
			break;
		} else {
			printf("Invalid choice.\n");
		}
	}
	return 0;
}
