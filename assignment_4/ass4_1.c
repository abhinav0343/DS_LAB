#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* createnew_node(int k){
    struct node*newnode;
    newnode=(struct node*)malloc(1*sizeof(struct node));
    newnode->data=k;
    newnode->next=NULL;
    return  newnode;
}
int main()
{
    int k,n,j;
    struct node*head,*temp,*last,*l,*pop;
    head=(struct node*)malloc(1*sizeof(struct node));
    temp=head;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    printf("enter the number of rotations :");
    scanf("%d",&j);
    printf("enter the data of the nodes \n");
    scanf("%d",&k);
    head->data=k;
    head->next=NULL;
    last=head;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&k);
        last->next=createnew_node(k);
        last=last->next;
    }
    l=head;
    pop=head;
    for(int i=0;i<n;i++)
    {
        if(i==j)
        {
            head=l;
        }
        l=l->next;      
    }
    temp=head;
    for(int i=0;i<n-j;i++)
    {
        if(i==n-j-1)
        {
        temp->next=pop;
        }
        temp=temp->next;
    }
    temp=head;
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            temp->next=NULL;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
