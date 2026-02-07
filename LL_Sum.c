#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//Creating a node
struct Node *creation_node(int data)
{
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));

    n->data = data;
    n->next = NULL;
    return n;
}

//Accept input for list
struct Node *create_list(int n)
{
    struct Node *head = NULL , *tail = NULL;

    int data_value;
    int counter;

    for(counter = 0 ; counter < n ; counter++)
    {
        printf("Enter value of node %d : ",counter+1);
        scanf("%d",&data_value);

        struct Node *temp = creation_node(data_value);

        if(head == NULL)
        {
            head =  tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

//Display List
void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

//Addition of lists
struct Node *add_lists(struct Node *list1 , struct Node *list2)
{
    struct Node *head = NULL , *tail = NULL;

    while(list1 != NULL || list2 != NULL)
    {
        int data1 , data2;

        if(list1 != NULL)
        {
            data1 = list1->data;
        }
        else
        {
            data1 = 0;
        }


        if(list2 != NULL)
        {
            data2 = list2->data;
        }
        else
        {
            data2 = 0;
        }

        struct Node *temp = creation_node(data1 + data2);

        if(head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

        if(list1 != NULL)
        {
            list1 = list1->next;
        }

        if(list2 != NULL)
        {
            list2 = list2->next;
        }
    }

    return head;
}


int main()
{
    int n1 , n2;

    //create list1
    printf("\nEnter number of nodes in list 1 : ");
    scanf("%d", &n1);

    printf("\nEnter elements of list 1 : \n");
    struct Node *list1 = create_list(n1);


    //create list2
    printf("\nEnter number of nodes in list 2 : ");
    scanf("%d", &n2);

    printf("Enter elements of list 2 : \n");
    struct Node *list2 = create_list(n2);

    //add list1 & list2
    struct Node *sum = add_lists(list1 , list2);

    printf("\nAddition of List 1 and List 2 : ");
    display(sum);
}