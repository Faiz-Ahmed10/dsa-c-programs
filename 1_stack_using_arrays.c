#include<stdio.h>
#include<stdlib.h>
#define MAX 5 

int stack_arr[MAX], top = -1;
void push(int data);
void pop(); 
void print();
void peek();
int isFull();
int isEmpty();

int main() {

	int choice;
	while(1) {
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.quit\nEnter you choice:");
		scanf("%d", &choice);

		switch(choice){
			case 1: int data;
					printf("Enter the element to be pushed:");
					scanf("%d", &data);
					push(data);
					break;
			case 2: pop();
					break;
			case 3: peek();
					break;
			case 4: print();
					break;
			case 5: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
	return 0;
}

int isFull(){
	if(top == MAX-1)
		return 1;
	else
		return 0;
}
int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}
void push(int data) {
	if(isFull()){
		printf("Stack overflow\n");
		return;
	}
	top++;
	stack_arr[top] = data;
	printf("%d is pushed to the stack\n", data);
}

void pop() {
	if(isEmpty()){
		printf("Stack underflow\n");
		return;
	}
	int x = stack_arr[top];
	top--;
	printf("%d is removed from the stack\n", x);
}

void print(){
	if(isEmpty()){
		printf("Stack is empty\n");
		return;
	}
	for(int i = top; i >= 0; i--)
		printf("%d\n", stack_arr[i]);
}

void peek() {
	if(isEmpty()){
		printf("Stack is empty\n");
		return;
	}
	printf("The topmost element of stack is:%d\n", stack_arr[top]);
}

