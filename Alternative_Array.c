#include<stdio.h>

int main()
{
    int n;
    
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    int array[n];

    //Accept the array
    int counter;
    for(counter = 0 ; counter < n ; counter++)
    {
        printf("Enter element %d : ",counter+1);
        scanf("%d", &array[counter]);
    }

    int positive[n];
    int negative[n];
    int positive_count = 0;
    int negative_count = 0;

    //Store positive , negative differently
    for(counter = 0 ; counter < n ; counter++)
    {
        if(array[counter] >= 0)
        {
            positive[positive_count++] = array[counter];
        }
        else
        {
            negative[negative_count++] = array[counter];
        }
    }

    //Merging Alternately
    int i, j, k;  //iterators
    i =0 , j= 0 , k= 0;

    while(i < positive_count && j < negative_count)
    {
        array[k++] = positive[i++];
        array[k++] = negative[j++];
    }

    //for left over 
    while(i < positive_count)
    {
        array[k++] = positive[i++];
    }

    while(j < negative_count)
    {
        array[k++] = negative[j++];
    }


    printf("\nRearranged Array : ");
    for(counter = 0 ; counter < n ; counter++)
    {
        printf("%d ",array[counter]);
    }
}