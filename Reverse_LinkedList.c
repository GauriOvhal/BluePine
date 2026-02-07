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


//reverse 
struct Node* reverse_list(struct Node *head) 
{
    //empty or single node
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    struct Node *previous = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while(current != NULL) 
    {
        //store next
        next = current->next;   

        //reverse link
        current->next = previous;   

        //move previous
        previous = current;
        
        //move current
        current = next;         
    }

    return previous;  // new head
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
    int n, value, i;

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
        {
            head = tail = temp;
        }
        else 
        {
            tail->next = temp;
            tail = temp;
        }
    }

    printf("\nOriginal List:\n");
    display(head);

    head = reverse_list(head);

    printf("\nReversed List:\n");
    display(head);
}
