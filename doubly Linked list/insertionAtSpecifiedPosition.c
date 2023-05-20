#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void insertStart(struct Node **head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

void insertLast(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->prev = NULL;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    newNode->prev = temp;
}

int calcSize(struct Node *node)
{
    int size = 0;

    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}

void insertPosition(int pos, int data, struct Node **head)
{
    int size = calcSize(*head);

    if (pos < 1 || size < pos)
    {
        printf("Can't insert, %d is not a valid position\n", pos);
    }
    else
    {
        struct Node *temp = *head;
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->data = data;
        newNode->next = NULL;

        while (--pos)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next = newNode;
    }
}

void display(struct Node *node)
{
    struct Node *end;
    printf("\nIn Forward Direction\n");
    while (node != NULL)
    {
        printf("%d  ", node->data);
        end = node;
        node = node->next;
    }

    printf("\n\nIn Backward direction \n");
    while (end != NULL)
    {
        printf("%d  ", end->data);
        end = end->prev;
    }
}

int main()
{
    struct Node *head = NULL;

    insertStart(&head, 1);
    insertStart(&head, 2);
    insertStart(&head, 3);

    insertLast(&head, 10);
    insertLast(&head, 20);

    insertPosition(2, 100, &head);

    display(head);

    return 0;
}