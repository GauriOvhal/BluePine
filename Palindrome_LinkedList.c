#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int intData;
    char strData[50];
    struct Node *next;
};

struct Node* create_node(int type) 
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    if(type == 1)
    {
        scanf("%d", &new_node->intData);
    }
    else
    {
        scanf("%s", new_node->strData);
    }

    new_node->next = NULL;

    return new_node;
}


struct Node* reverse(struct Node* head) 
{
    struct Node *prev = NULL, *current = head, *next = NULL;

    while(current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

int isPalindrome(struct Node* head, int type) 
{

    //no nodes or one node
    if(head == NULL || head->next == NULL)
    {
        return 1;
    }

    struct Node *slow = head, *fast = head;

    //middle
    while(fast->next != NULL && fast->next->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //Reverse second half
    struct Node *second_half = reverse(slow->next);
    struct Node *first_half = head;

    //Compare halves
    while(second_half != NULL) 
    {
        if(type == 1) 
        {
            if(first_half->intData != second_half->intData)
            {
                return 0;
            }
        } 
        else 
        {
            if(strcmp(first_half->strData, second_half->strData) != 0)
            {
                return 0;
            }
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return 1;
}

int main() 
{
    int n, i, type;

    printf("Enter data type (1-Integer, 2-String): ");
    scanf("%d", &type);

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    if(n == 0) 
    {
        printf("Linked list is empty and is a palindrome\n");
        return 0;
    }

    printf("Enter data:\n");
    for(i = 0; i < n; i++) 
    {
        struct Node *temp = create_node(type);

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

    if(isPalindrome(head, type))
    {
        printf("Linked List is a Palindrome\n");
    }
    else
    {
        printf("Linked List is NOT a Palindrome\n");
    }
}
