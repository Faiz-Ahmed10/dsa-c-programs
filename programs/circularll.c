#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct CircularLinkedList
{
    struct Node *head;
};

void initialize(struct CircularLinkedList *list)
{
    list->head = NULL;
}

void insertAtBeginning(struct CircularLinkedList *list, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Cannot insert element %d.\n", value);
        return;
    }
    newNode->data = value;

    if (list->head == NULL)
    {
        newNode->next = newNode;
        list->head = newNode;
    }
    else
    {
        newNode->next = list->head;
        struct Node *current = list->head;
        while (current->next != list->head)
        {
            current = current->next;
        }
        current->next = newNode;
        list->head = newNode;
    }
}

void insertAtEnd(struct CircularLinkedList *list, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Cannot insert element %d.\n", value);
        return;
    }
    newNode->data = value;

    if (list->head == NULL)
    {
        newNode->next = newNode;
        list->head = newNode;
    }
    else
    {
        struct Node *current = list->head;
        while (current->next != list->head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = list->head;
    }
}

void deleteAtBeginning(struct CircularLinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    struct Node *temp = list->head;
    if (list->head->next == list->head)
    {
        list->head = NULL;
    }
    else
    {
        struct Node *current = list->head;
        while (current->next != list->head)
        {
            current = current->next;
        }
        current->next = list->head->next;
        list->head = list->head->next;
    }
    free(temp);
}

void deleteAtEnd(struct CircularLinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    struct Node *temp = list->head;
    if (list->head->next == list->head)
    {
        list->head = NULL;
    }
    else
    {
        struct Node *current = list->head;
        struct Node *previous = NULL;
        while (current->next != list->head)
        {
            previous = current;
            current = current->next;
        }
        previous->next = list->head;
    }
    free(temp);
}

void display(struct CircularLinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List elements: ");
    struct Node *current = list->head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

void freeCircularList(struct CircularLinkedList *list)
{
    while (list->head != NULL)
    {
        struct Node *temp = list->head;
        if (list->head->next == list->head)
        {
            list->head = NULL;
        }
        else
        {
            struct Node *current = list->head;
            while (current->next != list->head)
            {
                current = current->next;
            }
            current->next = list->head->next;
            list->head = list->head->next;
        }
        free(temp);
    }
}

int main()
{
    struct CircularLinkedList myList;
    initialize(&myList);

    int choice, value;

    while (1)
    {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            insertAtBeginning(&myList, value);
            break;

        case 2:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            insertAtEnd(&myList, value);
            break;

        case 3:
            deleteAtBeginning(&myList);
            break;

        case 4:
            deleteAtEnd(&myList);
            break;

        case 5:
            display(&myList);
            break;

        case 6:
            freeCircularList(&myList);
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

