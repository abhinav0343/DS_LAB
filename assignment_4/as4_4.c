#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
void display(struct node **start) {
    struct node *temp = *start;
    printf("Your linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertbeg(struct node **start, int newdata) {
    struct node *insert_node = (struct node *)malloc(sizeof(struct node));
    if (insert_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    insert_node->data = newdata;
    insert_node->next = *start;
    insert_node->prev = NULL;
    if (*start != NULL)
        (*start)->prev = insert_node;

    *start = insert_node;
    display(start);
}
void insertmid(struct node **start, int newdata, int cnt) {
    if (cnt < 2) {
        printf("Not enough nodes to insert in the middle.\n");
        return;
    }
    struct node *temp = *start;
    struct node *insert_node = (struct node *)malloc(sizeof(struct node));
    if (insert_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    insert_node->data = newdata;
    int i = 1;
    while (i < (cnt / 2)) {
        temp = temp->next;
        i++;
    }
    insert_node->next = temp->next;
    insert_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = insert_node;   
    temp->next = insert_node;
    display(start);
}
void insertpos(struct node **start, int newdata, int position) {
    if (position == 1) {
        insertbeg(start, newdata);
        return;
    }
    struct node *temp = *start;
    struct node *insert_node = (struct node *)malloc(sizeof(struct node));
    if (insert_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    insert_node->data = newdata;

    int i = 1;
    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        free(insert_node);
        return;
    }
    insert_node->next = temp->next;
    insert_node->prev = temp;    
    if (temp->next != NULL)
        temp->next->prev = insert_node;   
    temp->next = insert_node;
    display(start);
}
void insertend(struct node **start, int newdata) {
    struct node *insert_node = (struct node *)malloc(sizeof(struct node));
    if (insert_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    insert_node->data = newdata;
    insert_node->next = NULL;
    if (*start == NULL) {
        insert_node->prev = NULL;
        *start = insert_node;
    } else {
        struct node *temp = *start;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = insert_node;
        insert_node->prev = temp;
    }
    display(start);
}
int main() {
    struct node *head = NULL, *temp, *newnode;
    int ch = 1, count = 0;
    while (ch == 1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL) {
            head = temp = newnode;
        } else {
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
        count++;

        printf("To continue press (1), to exit press (0): ");
        scanf("%d", &ch);
    }
    printf("Insert at beginning? (1-Yes, 0-No): ");
    scanf("%d", &ch);
    if (ch == 1) {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insertbeg(&head, data);
    }
    printf("Insert at end? (1-Yes, 0-No): ");
    scanf("%d", &ch);
    if (ch == 1) {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insertend(&head, data);
    }
    printf("Insert at specific position? (1-Yes, 0-No): ");
    scanf("%d", &ch);
    if (ch == 1) {
        int data, pos;
        printf("Enter the data: ");
        scanf("%d", &data);
        printf("Enter position: ");
        scanf("%d", &pos);
        insertpos(&head, data, pos);
    }
    printf("Insert in the middle? (1-Yes, 0-No): ");
    scanf("%d", &ch);
    if (ch == 1) {
        int data;
        temp = head;
        count = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("Enter the data: ");
        scanf("%d", &data);
        insertmid(&head, data,count);
    }
    display(&head);
    return 0;
}