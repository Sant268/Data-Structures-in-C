// C Doubly Linked List
//@kbooch GitHub
#include <stdio.h>
#include <stdlib.h>
int i = 0;

struct Node
{
   int data;
   struct Node *previous, *next;
} *head = NULL;

void insertAtEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   newNode -> next = NULL;
   if(head == NULL)
   {
      newNode -> previous = NULL;
      head = newNode;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> next != NULL)
         temp = temp -> next;
      temp -> next = newNode;
      newNode -> previous = temp;
   }
   printf("\nInsertion successful");
}
void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> previous = NULL;
    if(head == NULL)
    {
       newNode -> next = NULL;
       head = newNode;
    }
    else
    {
       newNode -> next = head;
       head -> previous = newNode;
       head = newNode;
    }
    printf("\nInsertion successful");
}

void deleteEnd()
{
   if(head == NULL)
      printf("List is Empty");
   else
   {
      struct Node *temp = head;
      if(temp -> previous == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         while(temp -> next != NULL)
            temp = temp -> next;
         temp -> previous -> next = NULL;
         free(temp);
      }
      printf("\nDeletion successful");
   }
}
void deleteBeginning()
{
   if(head == NULL)
      printf("List is Empty");
   else
   {
      struct Node *temp = head;
      if(temp -> previous == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         head = temp -> next;
         head -> previous = NULL;
         free(temp);
      }
      printf("\nDeletion successful");
   }
}
void traverse() {

   struct Node *ptr = head;
   printf("\n[ ");
   while(ptr != NULL) {
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }
   printf(" ]");
}

int main()
{
    int choice =0;
    int data = 0;
    while(choice != 9)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);
        if(choice == 1 || choice == 2)
        {
            printf("\n Specify value of node:");
            scanf("%d",&data);
        }
        switch(choice)
        {
            case 1:
            insertAtBeginning(data);
            break;
            case 2:
            insertAtEnd(data);
            break;
            case 3:
            deleteBeginning();
            break;
            case 4:
            deleteEnd();
            break;
            case 5:
            traverse();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("Please enter valid choice..");
        }
    }
    	return 0;
}


