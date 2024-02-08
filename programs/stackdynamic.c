#include <stdio.h>
#include <stdlib.h>

int * STACK, size, top=-1;

int isEmpty(){
    if (top==-1)
        return 1;
    else 
        return 0;
}

int isFull(){
    if (top == size-1)
        return 1;
    else 
        return 0;
}

void push(int n){
    if (STACK == NULL) return;
    if (isFull())
        printf("Stack Overflow\n");
    else {
        top++;
        STACK[top] = n;
    }
}

void pop(){
    if (STACK == NULL) return;
    if (isEmpty())
        printf("Stack Underflow\n");
    else {
        printf("%d is Deleted\n", STACK[top]);
        top--;
    }
}

void peek(){
    if (STACK == NULL) return;
    if(!isEmpty()){
        printf("%d\n", STACK[top]);
    } else 
        printf("Stack is Empty\n");
}

void display(){
    if (STACK == NULL) return;
    if (!isEmpty()){
        for (int i = top; i >= 0; i--)
        {
            printf("|%d|\n", STACK[i]);
        }
        
    } else 
        printf("Empty Stack\n");
}

void createStack(){
    if (STACK == NULL){
        printf("Enter Stack Size: ");
        scanf("%d", &size);
        STACK = (int *) malloc(size * sizeof(int));
    } else 
        printf("Stack Already Exist\n");
}

void deleteStack() {
    if (STACK == NULL)
        printf("Stack Doesn't Exist");
    else {
        free(STACK);
        STACK = NULL;
        top = -1;
    }
}

int main() {


    while (1)
    {
        printf("\n1. Create Stack\n2. Push \n3. Pop \n4. Peek \n5. Display \n6. Delete Stack\n7. Exit\nEnter Choice: \n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createStack();
            break;
        case 2:
            printf("Enter Number: ");
            int n;
            scanf("%d", &n);
            push(n);
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            display();
            break;
        case 6:
            deleteStack();
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Invalid\n");
            break;
        }
    }
    
}

