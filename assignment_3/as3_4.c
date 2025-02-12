#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data ;
    struct node *next;
};
int main()
{
    int n,count=0;
    printf("enter the size of array :\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter array values : \n");
    for(int i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    struct node *head=0,*temp,*newnode;
    for(int i=0;i<n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = arr[i];
        newnode->next = 0;
        if(head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp = head;
    printf("linked list after copying elements from array : \n");
    while(temp != 0)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
        count++;
    }
    printf("number of nodes in your linked list is : %d\n",count);
}