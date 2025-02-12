#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main()
{
    int n;
    struct node*head,*temp,*newnode;
    head = NULL;
    printf("enter the number of nodes :");
    scanf("%d",&n);
    printf("enter the data of the nodes : \n");
    for(int i=0;i<n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        scanf("%d",&newnode->data);
        if(head == NULL)
        {
          head = temp = newnode;
        }
        else 
        {
          temp->next=newnode;
          temp=temp->next;
        }
    }
    int pos;
    printf("enter the position to create loop from that node(1-based) , 0 for no loop : ");
    scanf("%d",&pos);
    if(pos == 0)
    {
        printf("no loop \n");
    }
    else
    {
        temp = head;
        struct node *loopnode = NULL;
        int count = 1;
        while(temp->next != NULL){
            if(count == pos){
                loopnode = temp;
            }
            temp = temp->next;
            count++;
        }
        temp->next = loopnode;
    }
    struct node *slow = head,*fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;//moves single step
        fast = fast->next->next;//move two step
        if(fast == slow)
        {
            printf("loop is detected \n");
            return 1;
        }
    }
    printf("NO loop is detected \n");
}