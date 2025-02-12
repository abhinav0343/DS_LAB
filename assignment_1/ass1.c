#include<stdio.h>
#include<stdlib.h>
  int main()
  {
    printf("enter the no:of values\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter the values of array \n");
      for(int i=0;i<n;i++)
      {
        scanf("%d",&a[i]);
      } 
    int temp;
    for(int i=0 ; i<n-1; i++)
    {
          for(int j=0;j<n-i-1 ;j++)
          {
            if(a[j] > a[j+1])
            {
               temp = a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
            }
          }
        
    } 
   int x;
   printf("enter the value of 'x' so that descending order will start \n") ;
   scanf("%d",&x);
   for(int i = x ; i < n-1 ; i++)
   {
         for(int j=x ; j < n -1 ; j++)
         {
            if(a[j] < a[j+1])
            {
                temp = a[j] ;
                a[j] = a[j+1];
                a[j+1] = temp;
            }
         }
   }
      printf("your BITONIC array\n");
       for( int i=0;i<n;i++)
       {
        printf("%d\t",a[i]);
       }
  }
