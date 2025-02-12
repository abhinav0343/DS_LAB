#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} NODE;

typedef struct {
    NODE *top;
    int size;
} STACK;

void create(STACK *s) {
    s->top = NULL;
    s->size = 0;
}
int isEmpty(STACK *s) {
    return s->top == NULL;
}
void push(STACK *s) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = s->top;
    s->top = newnode;
    s->size++;
}
void pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    NODE *temp = s->top;
    printf("Popped element: %d\n", temp->data);
    s->top = s->top->next;
    free(temp);
    s->size--;
}
void peek(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", s->top->data);
}
void display(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    NODE *temp = s->top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void getSize(STACK *s) {
    printf("Size of the stack: %d\n", s->size);
}
int main() {
    STACK s;
    create(&s);
    int choice;    
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Size\n");
    printf("0. Exit\n");   
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(&s); break;
            case 2: pop(&s); break;
            case 3: peek(&s); break;
            case 4: display(&s); break;
            case 5: getSize(&s); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);   
    return 0;
}
