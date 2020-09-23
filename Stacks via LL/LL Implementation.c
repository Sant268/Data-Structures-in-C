#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL; //here head of LL would be top of Stack

void traverse()
{
    struct Node* temp = top;
    if (top == NULL)
    {
        printf("\nStack Underflow");
        return;
    }
    printf("[ ");
    while (temp != NULL)
    {
        printf("  (%d)  ", temp->data);
        temp = temp->next;
    }
    printf(" ]");
}



void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
    printf("\nInsertion is Successful\n");
}

void pop()
{
    if (top == NULL)
        printf("\nUnderflow. Stack is empty\n");
    else
    {
        struct Node *temp = top;
        printf("\nDeleted element is: %d", temp->data);
        top = temp->next;
        free(temp);
    }
}

void main()
{
    int choice = 0, val = 0;
    while (choice != 99)
    {
        printf("\n =================================================================");
        printf("\n \t\t Stack via Linked List");
        printf("\n 1. Insert element in Stack");
        printf("\n 2. Delete element from Stack");
        printf("\n 3. Print Stack");
        printf("\n 99. Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter value to be inserted:");
            scanf("%d", &val);
        }
        switch (choice)
        {
        case 1:
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 99:
            exit(0);
        default:
            printf("\n Invalid Choice");
        }
    }
}
