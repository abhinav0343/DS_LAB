#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;

void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int space(char ch) {
    return ch == ' ' || ch == '\t';
}

void infixtopostfix() {
    int j = 0;
    char symbol;
    int len = strlen(infix);
    for (int i = 0; i < len; i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            if (isalnum(symbol)) {
                postfix[j++] = symbol;
            } else if (symbol == '(') {
                push(symbol);
            } else if (symbol == ')') {
                while (top != -1 && (symbol = pop()) != '(') {
                    postfix[j++] = symbol;
                }
            } else {
                while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
            }
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void print() {
    printf("Postfix Expression: %s\n", postfix);
}

char peek() {
    return stack[top];
}

int main() {
    printf("Enter the infix expression:\n");
    fgets(infix, MAX, stdin);
    infixtopostfix();
    print();
    return 0;
}
