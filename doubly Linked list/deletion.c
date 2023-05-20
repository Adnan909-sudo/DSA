#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
int getLength (struct Node *node);

void insert (struct Node **head, int data)
{

  struct Node *freshNode = (struct Node *) malloc (sizeof (struct Node));

  freshNode->data = data;
  freshNode->next = *head;
  freshNode->prev = NULL;


  if (*head != NULL)
    (*head)->prev = freshNode;

  *head = freshNode;
}

void deleteFront (struct Node **head)
{
  struct Node *tempNode = *head;


  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete\n");
      return;
    }


  if (tempNode->next == NULL)
    {
      printf ("%d deleted\n", tempNode->data);
      *head = NULL;
      return;
    }


  *head = (*head)->next;

  (*head)->prev = NULL;

  printf ("%d deleted\n", tempNode->data);
  free (tempNode);
}

void deleteEnd (struct Node **head)
{
  struct Node *tempNode = *head;


  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete\n");
      return;
    }


  if (tempNode->next == NULL)
    {
      printf ("%d deleted\n", tempNode->data);
      *head = NULL;
      return;
    }


  while (tempNode->next != NULL)
    tempNode = tempNode->next;

  struct Node *secondLast = tempNode->prev;


  secondLast->next = NULL;

  printf ("%d deleted\n", tempNode->data);
  free (tempNode);
}

void deleteNthNode (struct Node **head, int n)
{

  int len = getLength (*head);

  if (n < 1 || n > len)
    {
      printf ("Enter valid position\n");
      return;
    }


  if (n == 1)
    {
      deleteFront (head);
      return;
    }

  if (n == len)
    {
      deleteEnd (head);
      return;
    }

  struct Node *tempNode = *head;

 
  while (--n)
    {
      tempNode = tempNode->next;
    }

  struct Node *previousNode = tempNode->prev;	
  struct Node *nextNode = tempNode->next;	

  
  previousNode->next = tempNode->next;


  nextNode->prev = tempNode->prev;


  printf ("%d deleted \n", tempNode->data);
  free (tempNode);
}


int getLength (struct Node *node)
{
  int len = 0;


  while (node != NULL)
    {
      node = node->next;
      len++;
    }

  return len;
}


void display (struct Node *node)
{
  struct Node *end = NULL;

  printf ("List in Forward direction: ");
  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }

  printf ("\nList in backward direction:");

  while (end != NULL)
    {
      printf (" %d ", end->data);
      end = end->prev;
    }
  printf ("\n\n");
}

int main ()
{
  struct Node *head = NULL;

  insert (&head, 7);
  insert (&head, 8);
  insert (&head, 9);
  insert (&head, 10);
  insert (&head, 11);
  insert (&head, 12);

  display (head);

  deleteFront (&head);
  display (head);

  deleteEnd (&head);
  display (head);

  // delete 3rd node
  deleteNthNode (&head, 3);
  display (head);

  // delete 1st node
  deleteNthNode (&head, 1);
  display (head);

  // delete 1st node
  deleteEnd (&head);
  display (head);


  return 0;
}