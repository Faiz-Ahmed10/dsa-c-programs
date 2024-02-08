#include <stdio.h>
#include <stdlib.h>
int max, top = -1;

int isEmpty(int arr[])
{
	if (top == -1)
	{
		printf("Stack Underflow");
		return 1;
	}
	else
		return 0;
}

int isFull(int arr[])
{
	if (top == (max - 1))
	{
		printf("Stack Overflow");
		return 1;
	}
	else
		return 0;
}

void push(int arr[], int element)
{
	if (isFull(arr))
		return;
	arr[++(top)] = element;
	return;
}

int pop(int arr[])
{
	if (isEmpty(arr))
		return 0;
	return (arr[(top)--]);
}

void display(int arr[])
{
	int i;
	for (i = 0; i <= top; i++)
		printf("|%d|\n", arr[i]);
}

int main()
{

	printf("Enter Stack Size: ");
	scanf("%d", &max);

	int arr[max];
	int choice;
	int element;
	int top = -1;

	while (1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{

		case 1:
			printf("Enter element to be added : ");
			scanf("%d", &element);
			push(arr, element);
			break;
		case 2:
			pop(arr);
			break;
		case 3:
			display(arr);
			break;
		case 4:
			exit(1);
		}
	}
}

