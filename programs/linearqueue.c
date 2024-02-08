#include <stdio.h>
#include <stdlib.h>

int size = 10, queue[10], front=-1, rear=-1;

void enqueue(int n){
    if (rear == size-1)
        printf("Queue is Full\n");
    else {
        rear++;
        queue[rear] = n;
    }
}

void dequeue(){
    if (front == rear) 
        printf("Empty Queue\n");
    else {
        front++;
    }
}

void display(){
    if (front==rear)
        printf("Empty Queue\n");
    else {
        for (int i = front+1; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

void peek(){
    if (front == rear)
        printf("Empty Queue\n");
    else 
        printf("Peaked Value is: %d\n", queue[front+1]);
}

int main(){
    int n;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        int choice;
        printf("Enter Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Number: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid\n");
            break;
        }
    }
    
}

