#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *side;  //horizontal link
    struct Node *down;  //vertically link
};


struct Node* create_node(int data) 
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->side = NULL;
    n->down = NULL;
    return n;
}


struct Node* create_list(int n) 
{
    struct Node *head = NULL, *tail = NULL;
    int data;

    int i; //iterator
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &data);

        struct Node* temp = create_node(data);

        if(head == NULL)
            head = tail = temp;
        else 
        {
            tail->side = temp;
            tail = temp;
        }
    }
    return head;
}


struct Node* flatten(struct Node* head) 
{
    struct Node* current = head;

    while(current != NULL) 
    {
        if(current->down != NULL) 
        {
            struct Node* temp = current;

            while(temp->side != NULL)
                temp = temp->side;

            temp->side = current->down;
            current->down = NULL;
        }
        current = current->side;
    }
    return head;
}


void display(struct Node* head) 
{
    while(head) 
    {
        printf("%d -> ", head->data);
        head = head->side;
    }
    printf("NULL\n");
}

int main() 
{
    int num , i;

    printf("Enter number of linked lists: ");
    scanf("%d", &num);

    struct Node *head = NULL, *previous = NULL;

    for(i = 1; i <= num; i++) 
    {
        int n;
        printf("Enter number of nodes in list %d: ", i);
        scanf("%d", &n);

        printf("Enter elements: ");
        struct Node* list = create_list(n);

        if(head == NULL)
            head = list;
        else
            previous->down = list;

        previous = list;
    }

    printf("\nFlattened List:\n");
    head = flatten(head);
    display(head);
}
