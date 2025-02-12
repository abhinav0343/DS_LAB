#include<stdio.h>
#include<stdlib.h>
void readmatrix(int ***matrix,int rows,int cols)
{
    *matrix = (int **)malloc( rows * sizeof(int *)); // Allocating memory for matirx.
    for(int i=0;i<rows;i++)
    {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int)); // Allocating memory for each row.
    }
    printf("enter the elements of matrix in row wise \n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&(*matrix)[i][j]); // this points to the ith row and jth column .
        }
    }
}
void product(int **mat1,int**mat2,int ***result,int r1,int c1,int c2)
{
    *result = (int **)malloc( r1 * sizeof(int *)); //allocating memory for result matrix.
    for(int i = 0; i < r1; i++)
    {
      (*result)[i] = (int *)malloc( c2 * sizeof(int)); // allocating memory for each row in result matrix.
    }
    for(int i=0; i < r1; i++)
    {
        for(int k=0; k < c2 ; k++)
        {
           (*result)[i][k] = 0 ; // Giving '0' to every starting element in each row .
            for(int j=0; j < c1; j++)
            {
              (*result)[i][k] = (*result)[i][k] + mat1[i][j] * mat2[j][k];  // no:of columns in first matirx is equal to no:of rows in matrix 2.
            }
        }
    }
}
void display(int **mat1,int **mat2,int **result,int row1,int col1,int row2,int col2)
{
    printf("your first matrix is \n");
   for(int i=0;i<row1;i++)
   {
    for(int j=0;j<col1;j++)
    {
        printf("%d\t",mat1[i][j]);
    }
    printf("\n");
   }
     printf("your second matrix is \n");
   for(int i=0;i<row2;i++)
   {
    for(int j=0;j<col2;j++)
    {
        printf("%d\t",mat2[i][j]);
    }
    printf("\n");
   }
     printf("your resultant matrix is \n");
   for(int i=0;i<row1;i++)
   {
    for(int j=0;j<col2;j++)
    {
        printf("%d\t",result[i][j]);
    }
    printf("\n");
   }
}
 int main()
 {
    int r1,c1,r2,c2;
    int **mat1,**mat2,**result; //here we are using  **mat1 because we are dealing with 2D arrays.
    printf("enter the no:of rows and columns in matrix '1' \n");
    scanf("%d %d",&r1,&c1);
    printf("enter the no:of rows and columns in matrix '2' \n");
    scanf("%d%d",&r2,&c2);
     if( c1 != r2)
     {
        printf("multiplication is not possible if no:of columns in matrix '1' is not equal to no:of rows in matrix '2' \n");
        return 1;  // for exiting the program.
     }
     else
     {
        readmatrix(&mat1,r1,c1);
        readmatrix(&mat2,r2,c2);
        product(mat1,mat2,&result,r1,c1,c2);
        display(mat1,mat2,result,r1,c1,r2,c2);
     }

/*we are allocating memory for 2D arrays (matrices) dynamically. Each 2D array consists of:
A pointer to an array of pointers (for the rows of the matrix).
Each row itself is an array of integers (the actual data of the matrix). */

     for(int i=0;i<r1;i++)
     {
        free(mat1[i]); // free each row of mat1 (which is an array of pointers)
     }
     free(mat1); //free array of pointers (pointer to rows).
     for(int i=0;i<r2;i++)
     {
        free(mat2[i]);
     }
     free(mat2);
     for(int i=0;i<r1;i++)
     {
        free(result[i]);
     }
     free(result);
 }
