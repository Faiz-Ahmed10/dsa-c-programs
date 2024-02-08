#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head, *temp;

void insertAtBeg(int data);
void insertAtMid(int pos, int data);
void insertAtEnd(int data);
void display();

int main() {

    printf("Enter Element: \n");
    int data, pos;
    scanf("%d", &data);
    head = (struct node *) malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;

    while (1)
    {
        printf("\n1.Insert at Beginning\n2.Insert At Position\n3.Insert at End\n4.Display\n5.Exit\n");
        int choice;
        printf("Enter Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Number: \n");
            scanf("%d", &data);
            insertAtBeg(data);
            break;
        case 2:
            printf("Enter Position: \n");
            scanf("%d", &pos);
            printf("Enter Number: \n");
            scanf("%d", &data);
            insertAtMid(pos, data);
            break;
        case 3:
            printf("Enter Number: \n");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid\n");
            break;
        }
    }
    
}

void insertAtBeg(int data) {
    temp  = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtMid(int pos, int data){
    temp = head;

    if (pos == 0) {
        insertAtBeg(data);
        return;
    }

    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position not found\n");
            return;
        }
        temp = temp->next;
    }

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = temp->next;
    temp->next = ptr;
}

void insertAtEnd(int data){
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    temp->next = ptr;
}

void display(){
    temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

