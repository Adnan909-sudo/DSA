#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    int num;                        
    struct node *nextptr;   
}*stnode;

void createNodeList(int n);  
void To_Array(struct node *head, int *array);
    
int main()
{
    int n;
    printf("\nLinked List: Convert a Singly Linked list into an array:\n");
	printf("-------------------------------------------------------------\n");		
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\nReturn data entered in the list as an array:\n");
    int arr[n];
    To_Array(stnode, arr);
    for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
    return 0;
}

void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) 
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

      for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
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
void To_Array(struct node *head, int *array) {
    struct node *current = head;
    int i = 0;
    while (current != NULL) {
        array[i] = current->num;
        current = current->nextptr;
        i++;
    }
}
