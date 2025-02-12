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
   int num=1,count=0;
   while(1)
   {
    if(num==1)
    {
      newnode = (struct node *)malloc(sizeof(struct node));
      printf("enter the data :\n");
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
        printf("for CONTINUE OR EXIT (1,0) respectively :\n");
        scanf("%d",&num);
    }
    else if (num == 0)
    {
      temp = head;
      printf("your list is :\n");
      while(temp != 0)
      {
       printf("%d\n",temp->data);
       temp = temp->next;
       count++;
      }
      printf("no:of nodes in your list is : %d\n",count);
      break;
     }
   }
 }
