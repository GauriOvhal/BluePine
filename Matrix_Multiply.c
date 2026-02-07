#include <stdio.h>
#include <stdlib.h>

//Allocation of matrix
int **create(int row, int column)
{
    int i, j;

    int **matrix = (int **)malloc(row * sizeof(int *));

    for(i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(column * sizeof(int));
    }
    return matrix;
}


//Accept matrix elements
void accept(int **matrix, int row, int column)
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}


//Display matrix
void display(int **matrix, int row, int column)
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


//Multiplication
int **multiply(int **A, int **B, int r1, int c1, int c2)
{
    int i, j, k;

    int **product = create(r1, c2);

    for(i = 0; i < r1; i++)
    {        
        for(j = 0; j < c2; j++)
        {
            product[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return product;
}

int main()
{
    int i, j;

    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    int **A = create(r1, c1);
    printf("Enter Matrix A elements:\n");
    accept(A, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    int **B = create(r2, c2);
    printf("Enter Matrix B elements:\n");
    accept(B, r2, c2);

    int diff = c1 - r2;

    if(diff == 0)
    {
        //perform multiplication
        int **product = multiply(A, B, r1, c1, c2);
        printf("\nResult Matrix:\n");
        display(product, r1, c2);
    }

    else if(diff < 0)
    {
        //expand Matrix A columns
        int **newA = create(r1, r2);

        //copy the old values
        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c1; j++)
            {
                newA[i][j] = A[i][j];
            }
        }

        printf("Enter values for expanded columns of Matrix A:\n");
        for(i = 0; i < r1; i++)
        {
            for(j = c1; j < r2; j++)
            {
                scanf("%d", &newA[i][j]);
            }
        }

        A = newA;
        c1 = r2;
        
        //perform multiplication
        int **product = multiply(A, B, r1, c1, c2);
        printf("\nResult Matrix:\n");
        display(product, r1, c2);
    }

    else     //diff > 0
    {
        //expand Matrix B rows
        int **newB = create(c1, c2);

        //copy old values
        for(i = 0; i < r2; i++)
        {
            for(j = 0; j < c2; j++)
            {
                newB[i][j] = B[i][j];
            }
        }

        printf("Enter values for expanded rows of Matrix B:\n");
        for(i = r2; i < c1; i++)
        {
            for(j = 0; j < c2; j++)
            {
                scanf("%d", &newB[i][j]);
            }
        }

        B = newB;
        r2 = c1;

        //perform multiplication
        int **product = multiply(A, B, r1, c1, c2);
        printf("\nResult Matrix:\n");
        display(product, r1, c2);
    }
}
