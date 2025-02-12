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
 int num = 1;
 while(num==1)
 {
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter data \n");
   scanf("%d",&newnode->data);
   newnode->next = 0;
   if(head==0)
   {
     head=temp=newnode;
   } 
   else
   {
     temp->next=newnode;
     temp=newnode;
   }
   printf("for countinue or exit (1,0) respectively \n");
   scanf("%d",&num);
 }
   temp = head;
   printf("initial linked list \n");
     while(temp != 0)
     {
       printf("%d\n",temp->data);
       temp = temp->next;
     }
  
   struct node *insert_node;
   insert_node=(struct node*)malloc(sizeof(struct node));
   insert_node->next = 0;
   printf("enter data you want to insert at beginning \n");
   scanf("%d",&insert_node->data);
   insert_node->next = head;
   head = insert_node;
   temp=head;
   printf("your linked list after inserting is : \n");
   while(temp != 0)
   {
     printf("%d\n",temp->data);
     temp = temp->next;
   } 
   return 0;
 }  