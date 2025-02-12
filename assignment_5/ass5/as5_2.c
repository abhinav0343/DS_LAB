#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct stack {
    int stArr[MAXSIZE];
    int top;
} STACK;
void create(STACK *s) {
    s->top = -1;
}
int isFull(STACK *s) {
    return s->top == MAXSIZE - 1;
}
int isEmpty(STACK *s) {
    return s->top == -1;
}
void push(STACK *s) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    s->stArr[++(s->top)] = x;
}
void pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Value removed: %d\n", s->stArr[(s->top)--]);
}
void peek(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top value: %d\n", s->stArr[s->top]);
}
void display(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->stArr[i]);
    }
    printf("\n");
}

int main() {
    STACK s;
    create(&s);
    int choice;
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Check if Full\n");
    printf("6. Check if Empty\n");
    printf("0. Exit\n");  
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(&s); break;
            case 2: pop(&s); break;
            case 3: peek(&s); break;
            case 4: display(&s); break;
            case 5: printf(isFull(&s) ? "Stack is full!\n" : "Stack is not full!\n"); break;
            case 6: printf(isEmpty(&s) ? "Stack is empty!\n" : "Stack is not empty!\n"); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);   
    return 0;
}
