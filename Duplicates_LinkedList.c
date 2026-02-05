#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node* create_node(int data) 
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


void remove_duplicates(struct Node *head) 
{
    //empty or single node
    if(head == NULL || head->next == NULL)
    {
        return;
    }

    struct Node *current = head;

    while(current != NULL) 
    {
        struct Node *counter = current;

        while(counter->next != NULL) 
        {
            if(counter->next->data == current->data) 
            {
                //duplicate found
                struct Node *temp = counter->next;
                counter->next = counter->next->next;
                free(temp);
            } 
            else 
            {
                counter = counter->next;
            }
        }
        current = current->next;
    }
}


void display(struct Node *head) 
{
    if(head == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    while(head != NULL) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() 
{
    int n, i, value;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n == 0) 
    {
        printf("Empty list\n");
        return 0;
    }

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        struct Node *temp = create_node(value);

        if(head == NULL)
            head = tail = temp;
        else 
        {
            tail->next = temp;
            tail = temp;
        }
    }

    printf("\nOriginal List:\n");
    display(head);

    remove_duplicates(head);

    printf("\nAfter Removing Duplicates:\n");
    display(head);

}
