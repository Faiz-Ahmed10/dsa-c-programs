#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int n) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = n;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Empty Queue\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Empty Queue\n");
    } else {
        printf("Queue: ");
        int i;
        for (i = front; i != (rear + 1) % SIZE; i = (i + 1) % SIZE) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


void peek() {
    if (front == -1) {
        printf("Empty Queue\n");
    } else {
        printf("Peeked Value is: %d\n", queue[front]);
    }
}

int main() {
    int n;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        int choice;
        printf("Enter Choice: \n");
        scanf("%d", &choice);
        switch (choice) {
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
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

