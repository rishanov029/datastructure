#include <stdio.h>
#include <stdlib.h>

int cqueue[6];
int front = -1, rear -1, n=6;

void enqueue(int val){
    if ((front == 0 && rear == n-1) || (front == rear+1)){
        printf("Queue overflow\n");
        return;
    }
    if (front==-1){
        front = 0;
        rear = 0;

    }
    else{
        if (rear== n-1)
        rear = 0;
        else
        {
            rear = rear + 1;
        }
        cqueue[rear] = val;
        
    }
    void dequeue(){
        if (front == -1)
    {
    printf("Queue Underflow\n");
    return;
}
printf("Element deleted from queue is: %d", cqueue[front]);
if(front == rear){
    front = -1;
    rear = -1;
}
else{
    if (front == n-1)
    front = 0;
    else
    front = front + 1;
}
}
}
void display(){
    int f = front, r = rear;
    if (front == -1){
        printf("Queue is empty");
        return;
    }
    printf("Queue elements are : \n");
    if (f <=r){
        while(f <=r){
            printf("%d", cqueue[f]);
            f++;

        }
    }
    else{
        while (f<=n - 1){
            printf("%d", cqueue[f]);
            f++;
        }
        f = 0;
        while(f<=r){
            printf("%d", cqueue[f]);
            f++;
        }
    }
}

int menu(){
    int choice;
    printf("\n1. Add value to the list: ");
    printf("\n2. Delete value to the list: ");
    printf("\n3. View list: ");
    printf("\n4. Exit\n");
    printf("\n Please enter your choice:\t");
    scanf("%d", &choice);
    return(choice);

}
void main(){
    int value;
    while(1){
        switch(menu()){
            case 1:
                printf("Input for insertion: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");

        }
    }

}
