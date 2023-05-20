#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *nextptr;
} *stnode;

void createNodeList(int n);
void insertNodeAtMiddle(int num, int pos);
void displayList();

int main()
{
    int n, num, pos;
    printf("\n\n Linked List : Insert a new node at the middle of the Linked List :\n");
    printf("-----------------------------------------------------------------------\n");

    printf(" Input the number of nodes (3 or more) : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list are : \n");
    displayList();
    printf("\n Input data to insert in the middle of the list : ");
    scanf("%d", &num);
    printf(" Input the position to insert new node : ");
    scanf("%d", &pos);
    if (pos <= 1 || pos >= n)
    {
        printf("\n Insertion can not be possible in that position.\n ");
    }
    if (pos > 1 && pos < n)
    {
        insertNodeAtMiddle(num, pos);
        printf("\n Insertion completed successfully.\n ");
    }
    printf("\n The new list are : \n");
    displayList();
    return 0;
}
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL;
        tmp = stnode;

        for (i = 2; i <= n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if (fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);

                fnNode->num = num;
                fnNode->nextptr = NULL;

                tmp->nextptr = fnNode;
                tmp = tmp->nextptr;
            }
        }
    }
}

void insertNodeAtMiddle(int num, int pos)
{
    int i;
    struct node *fnNode, *tmp;
    fnNode = (struct node *)malloc(sizeof(struct node));
    if (fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num;
        fnNode->nextptr = NULL;
        tmp = stnode;
        for (i = 2; i <= pos - 1; i++)
        {
            tmp = tmp->nextptr;

            if (tmp == NULL)
                break;
        }
        if (tmp != NULL)
        {
            fnNode->nextptr = tmp->nextptr;
            tmp->nextptr = fnNode;
        }
        else
        {
            printf(" Insert is not possible to the given position.\n");
        }
    }
}

void displayList()
{
    struct node *tmp;
    if (stnode == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = stnode;
        while (tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);
            tmp = tmp->nextptr;
        }
    }
}
