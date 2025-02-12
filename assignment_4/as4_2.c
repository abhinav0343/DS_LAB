#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void display(struct node *head) {
    struct node *temp = head;
    if (temp == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    printf("\nLinked list elements: \n");
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void removeduplicate(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp, *prev, *current;
    temp = head;
    while (temp != NULL && temp->next != NULL) {
        prev = temp;
        current = temp->next;
        while (current != NULL) {
            if (temp->data == current->data) {
                prev->next = current->next;  // Skip the duplicate node
                free(current);  
                current = prev->next;  // Move current  to the next node
            } else {
                prev = current;  // Move prev to the current node
                current = current->next;  
            }
        }
        temp = temp->next;  
    }
}
int main() {
    struct node *head = NULL, *temp, *newnode;
    int ch = 1;
    while (ch == 1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("To continue, press 1. To exit, press 0: ");
        scanf("%d", &ch);
    }
    printf("Initially, your linked list is: \n");
    display(head);
    removeduplicate(head);
    printf("\nAfter removing duplicates, your linked list is: \n");
    display(head);
    return 0;
}
