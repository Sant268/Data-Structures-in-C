#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void printLL()
{
    printf("\n The Linked List currently is:");
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void insertEnd(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("\nInsertion successful \n");
}

void insertBegin(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
    printf("\nInsertion successful \n");
}
void delEnd()
{
    if (head == NULL)
        printf("List is Empty");
    else
    {
        struct Node *temp1 = head, *temp2;
        if (temp1->next == head)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            while (temp1->next != head)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = head;
            free(temp1);
        }
        printf("\nDeletion successful \n");
    }
}

void delBegin()
{
    if (head == NULL)
        printf("List is Empty");
    else
    {
        struct Node *temp = head, *last = NULL;
        if (temp->next == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != head)
                temp = temp->next;
            last = temp;
            temp = head;
            head = head->next;
            free(temp);
            last->next = head;
        }
        printf("\nDeletion successful \n");
    }
}

void main()
{
    int ch = -1, x = 0;
    while (ch != 99)
    {
        printf("\n 1. Insert at Beginning of CLL");
        printf("\n 2. Insert at End of CLL");
        printf("\n 3. Delete Beginning Node");
        printf("\n 4. Delete End Node");
        printf("\n 99. Exit the Program");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        if (ch == 1 || ch == 2)
        {
            printf("\n Enter Value to Insert:");
            scanf("%d", &x);
        }
        switch (ch)
        {
        case 1:
            insertBegin(x);
            printLL();
            break;
        case 2:
            insertEnd(x);
            printLL();
            break;
        case 3:
            delBegin();
            printLL();
            break;
        case 4:
            delEnd();
            printLL();
            break;
        case 99:
            printf("\n Thank You");
            break;
        default:
            break;
        }
    }
}
