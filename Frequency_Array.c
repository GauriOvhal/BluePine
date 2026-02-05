#include<stdio.h>

int main()
{
    int choice;
    printf("Enter choice (1-Number, 2-Character): ");
    scanf("%d", &choice);

    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid array size.");
        return 0;
    }

    int i, j;   //iterator

    int visited[n];  //so that no counting one element many times
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    //for num
    if(choice == 1)
    {
        int arr[n];

        printf("Enter elements:\n");
        for(i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("\nFrequency:\n");
        for(i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                continue;
            }

            int count = 1;
            for(j = i + 1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    count++;
                    visited[j] = 1;
                }
            }
            printf("%d -> %d\n", arr[i], count);
        }
    }

    //char
    else if(choice == 2)
    {
        char arr[n];

        printf("Enter elements:\n");
        for(i = 0; i < n; i++)
        {
            scanf(" %c", &arr[i]);
        }

        printf("\nFrequency:\n");
        for(i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                continue;
            }

            int count = 1;
            for(j = i + 1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    count++;
                    visited[j] = 1;
                }
            }
            printf("%c -> %d\n", arr[i], count);
        }
    }

    else
    {
        printf("Invalid choice.");
    }
}
