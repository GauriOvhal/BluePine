#include<stdio.h>

int main()
{
    printf("\nSPIRAL MATRIX : ");

    printf("\nSquare matrix is required to print a spiral matrix which means the number of rows and columns should be same");

    int size;
    printf("\nEnter size of matrix : ");
    scanf("%d", &size);

    if(size % 2 == 0)
    {
        printf("\nSpiral matrix not possible because of even size.");
    }

    else
    {
        int m[size][size];

        //Accept matrix elements
        int counter1 , counter2; //Iterators

        for(counter1 = 0 ; counter1 < size ; counter1++)
        {
            for(counter2 = 0 ; counter2 < size ; counter2++)
            {
                printf("Enter element for cell [%d][%d] : ",counter1, counter2);
                scanf("%d", &m[counter1][counter2]);
            }
        }

        //Display the matrix 
        printf("\nMatrix : \n");
        for(counter1 = 0 ; counter1 < size ; counter1++)
        {
            for(counter2 = 0 ; counter2 < size ; counter2++)
            {
                printf("%d ",m[counter1][counter2]);
            }
            printf("\n");
        }
        

        //SPIRAL MATRIX
        int row = size/2;
        int column = size/2;
        printf("\nSPIRAL MATRIX SEQUENCE : ");
        printf("%d ",m[row][column]);   //print the center element of the matrix

        int i; //iterator
        int count = 1;
        int step =1 ;
        int total = size*size;

        while(count < total)
        {
            //Move up
            for(i = 0 ; i < step && count < total ; i++)
            {
                row--;
                printf("%d ", m[row][column]);
                count++;
            }

            //Move left
            for(i= 0 ; i < step && count < total ; i++)
            {
                column--;
                printf("%d ",m[row][column]);
                count++;
            }

            step++;


            //Move down
            for(i = 0 ; i < step && count < total ; i++)
            {
                row++;
                printf("%d ", m[row][column]);
                count++;
            }


            //Move right
            for(i = 0 ; i < step && count < total ; i++)
            {
                column++;
                printf("%d ", m[row][column]);
                count++;
            }

            step++;
        }
    }
}