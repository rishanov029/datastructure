#include <stdio.h>
#include <stdlib.h>

typedef struct DisjointSet {
    int *parent;
    int *rank;
    int size;
} DisjointSet;

static int makeset(DisjointSet *set, int size)
{
    int *parent;
    int *rank;
    int index;

    if (set == NULL || size <= 0) return 0;

    parent = malloc((size_t)size * sizeof(*parent));
    rank = calloc((size_t)size, sizeof(*rank));
    if (parent == NULL || rank == NULL) {
        free(parent);
        free(rank);
        return 0;
    }

    for (index = 0; index < size; index++)
        parent[index] = index;

    set->parent = parent;
    set->rank = rank;
    set->size = size;
    return 1;
}

static int find_set(DisjointSet *set, int element)
{
    if (set == NULL || set->parent == NULL ||
        element < 0 || element >= set->size)
        return -1;

    if (set->parent[element] != element)
        set->parent[element] = find_set(set, set->parent[element]);
    return set->parent[element];
}

static int union_sets(DisjointSet *set, int first, int second)
{
    int first_root = find_set(set, first);
    int second_root = find_set(set, second);

    if (first_root == -1 || second_root == -1) return -1;
    if (first_root == second_root) return 0;

    if (set->rank[first_root] < set->rank[second_root]) {
        set->parent[first_root] = second_root;
    } else if (set->rank[first_root] > set->rank[second_root]) {
        set->parent[second_root] = first_root;
    } else {
        set->parent[second_root] = first_root;
        set->rank[first_root]++;
    }
    return 1;
}

static void displayset(const DisjointSet *set)
{
    int index;

    printf("Element\tParent\tRank\n");
    for (index = 0; index < set->size; index++)
        printf("%d\t%d\t%d\n", index, set->parent[index], set->rank[index]);
}

static void destroyset(DisjointSet *set)
{
    free(set->parent);
    free(set->rank);
    set->parent = NULL;
    set->rank = NULL;
    set->size = 0;
}

int main(void)
{
    DisjointSet set = {NULL, NULL, 0};
    int size;
    int choice;
    int element;
    int first;
    int second;
    int result;

    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    if (!makeset(&set, size)) {
        printf("Could not create the disjoint set.\n");
        return 1;
    }

    do {
        printf("\nDisjoint Set Operations\n");
        printf("1. Find representative\n2. Union two elements\n");
        printf("3. Display sets\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            destroyset(&set);
            return 1;
        }

        switch (choice) {
        case 1:
            printf("Enter element (0 to %d): ", size - 1);
            if (scanf("%d", &element) != 1) {
                destroyset(&set);
                return 1;
            }
            result = find_set(&set, element);
            if (result == -1)
                printf("Element is out of range.\n");
            else
                printf("Representative: %d\n", result);
            break;
        case 2:
            printf("Enter two elements to union (0 to %d): ", size - 1);
            if (scanf("%d%d", &first, &second) != 2) {
                destroyset(&set);
                return 1;
            }
            result = union_sets(&set, first, second);
            if (result == -1)
                printf("Element is out of range.\n");
            else if (result == 0)
                printf("Elements are already in the same set.\n");
            else
                printf("Sets united.\n");
            break;
        case 3:
            displayset(&set);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    destroyset(&set);
    return 0;
}