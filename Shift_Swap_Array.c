#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 1)
    {
        printf("No shifting needed.\n");
        return 0;
    }

    int arr[n];

    //accept array
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //index of maximum element
    int max_index = 0;
    for(i = 1; i < n; i++)
    {
        if(arr[i] > arr[max_index])
        {
            max_index = i;
        }
    }

    //if max already at last position
    if(max_index == n - 1)
    {
        printf("Array after shifting:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        return 0;
    }

    int max_value = arr[max_index];

    //shift elements to the left
    for(int i = max_index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = max_value;

    
    printf("Array after shifting:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
