#include<stdio.h>
#include<stdlib.h>
struct array 
{
   int *ptr1;
   int *ptr2;
};
 int main()
 {
    struct array ak;
    int n;
    printf("enter the size of array \n");
    scanf("%d",&n);
    ak.ptr1 = (int *)calloc(n , sizeof(int));  // ptr1 is an int *, so you should allocate memory for integers, not pointers.
    ak.ptr2 = (int *)calloc(n , sizeof(int));  // and here these pointers are in the structures so you should use ak.pt1/ak.ptr2.
    printf("enter your first array\n");
    for(int i=0 ; i<n ; i++)
    {
       scanf("%d",&ak.ptr1[i]);   // this is subscript notation (square brackets)
    }
    for(int i=0 ; i<n ; i++)
    {
        int j = (i > 0) ? i-1 : 0 ;
        int k = (i < n - 1) ? i+1 : n-1 ;
        if(i % 2 != 0 && i < n - 1)
        {
            ak.ptr2[i] = ak.ptr1[j] * ak.ptr1[k] ;
        }
        else
        {
            ak.ptr2[i] = ak.ptr1[i];    
        }
    }
    printf("your first array is  : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", *(ak.ptr1 + i)); // this is alternative way for subscipt notation.
    }
    printf("\n");
    printf("your second array is  : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t", *(ak.ptr2 + i)); // this is alternative way for subscipt notation.
    }
 }
