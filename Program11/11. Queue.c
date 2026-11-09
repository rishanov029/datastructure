#include <stdio.h>
#define MAX 10

void insert();
void delete();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;

int main(void){
    int choice;
    while(1){
        printf("1. Insert element to queue \n");
        printf("2. Delete element from queue \n");
        printf("3. Display all elements of queue \n");
        printf("4. Quit \n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}

void insert(void){
    int item;

    if (rear == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }

    printf("Enter the element to insert: ");
    if (scanf("%d", &item) != 1) {
        printf("Invalid input.\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }
    queue_array[++rear] = item;
    printf("Inserted %d.\n", item);
}

void delete(void){
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue_array[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void display(void){
    int index;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (index = front; index <= rear; index++) {
        printf("%d ", queue_array[index]);
    }
    printf("\n");
}

