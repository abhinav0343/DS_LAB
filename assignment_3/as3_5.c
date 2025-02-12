#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head=0,*temp,*newnode;
    int num = 1,count = 0;
    while(1)
    {
        if(num == 1)
        {
          newnode = (struct node*)malloc(sizeof(struct node));
          printf("enter your data that you want to store in linked list \n");
          scanf("%d",&newnode->data);
          newnode->next = 0;
          if(head == 0)
          {
            head = temp = newnode;
          }
          else
          {
            temp->next = newnode;
            temp = newnode;
          }
          count++;
          
          printf("for continue or stop press (1,0) respectively \n");
          scanf("%d",&num);
        }
        else if(num != 1 && num != 0)
        {
            printf("invalid number \n");
            break;
        }
        else if(num == 0)
        {
          temp = head;
          int arr[count];
          for(int i=0;i<count;i++)
          {
            arr[i]=temp->data;
            temp=temp->next;
          }
           printf("your array after copying elements from linked list :\n");
           for(int i=0;i<count;i++)
           {
            printf("%d\n",arr[i]);
           }
           break;
        }
    }
       
}