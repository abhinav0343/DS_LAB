#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *last = NULL;
void insertBeginning(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}
void insertEnd(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    if (last == NULL || pos == 1) {
        insertBeginning(value);
        return;
    }
    struct node *temp = last->next;
    for (int i = 1; temp != last && i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) {
        last = newNode;
    }
}
void deleteBeginning() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = last->next;
    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    free(temp);
}
void deleteEnd() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = last->next;
    if (last->next == last) {
        free(last);
        last = NULL;
        return;
    }
    while (temp->next != last) {
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    last = temp;
}
void deleteAtPosition(int pos) {
    if (last == NULL || pos < 1) {
        printf("Invalid position or list is empty!\n");
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    struct node *temp = last->next, *prev;
    for (int i = 1; temp != last && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == last) {
        deleteEnd();
    } else {
        prev->next = temp->next;
        free(temp);
    }
}
void display() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}
int main() {
    int choice, value, position;
    do {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Display\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: ");
                    scanf("%d", &value); 
                    insertBeginning(value);
                    break;
            case 2: printf("Enter value: ");  
                    scanf("%d", &value); 
                    insertEnd(value); 
                    break;
            case 3: printf("Enter value and position: "); 
                    scanf("%d %d", &value, &position); 
                    insertAtPosition(value, position); 
                    break;
            case 4: deleteBeginning(); 
                    break;
            case 5: deleteEnd(); 
                    break;
            case 6: printf("Enter position: "); 
                    scanf("%d", &position);
                    deleteAtPosition(position); 
                    break;
            case 7: display(); 
                    break;
            case 0: printf("Exiting...\n"); 
                    break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    return 0;
}
