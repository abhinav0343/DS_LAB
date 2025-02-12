#include<stdio.h>
int main()
{
    int n,i,j;
    printf("enter the number of values \n");
    scanf("%d",&n);
    int a[n];
    printf("enter the values of array \n");
     for(i=0;i<n;i++)
     {
        scanf("%d",&a[i]);
     }
     int count = 0;
    for(i=0;i<n;i++)
    {
        for(j=i+1 ; j < n ; j++)
        {
                if(a[i]>a[j])
                {
                    count++;
                }          
        }
    }
    printf("number of inversions is %d",count);
}