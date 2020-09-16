#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*head = NULL;


void insert_beginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    if(head == NULL)
    {
        newNode -> next = NULL;
        head = newNode;
    }
    else
    {
        newNode -> next = head;
        head = newNode;
    }
    printf("\n Node inserted successfuly");
}

void insert_ending(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next
        }
        temp -> next = newNode;
    }
    printf("\n Node inserted successfuly");
}

void insert_after(int value,int pos)
{
    int i = 0;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    if(head == NULL)
    {
        newNode -> next = NULL;
    }
    else
    {
        struct Node *temp = head;
        for(i = 0;i < pos - 1;i++)
        {
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    printf("\n Node inserted successfuly");
}

void printLL(struct Node *n)
{
    while(n != NULL)
    {
        printf("\n Node %d:",i,n->value);
        n = n->next;
    }
}

void main() {
    int ch = -1;
    while(ch != 99){
    printf("\n Enter your choice:");
    printf("\n Insert at beginning");
    printf("\n Insert at End");
    printf("\n Insert at Position");
    printf("\n Print Linked List");
    scanf("%d",&ch);
    switch(ch)
}
}
