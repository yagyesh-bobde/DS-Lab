// TODO: Check if the given expression is balanced or not i mean parentheses wise


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
bool is_empty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
bool is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *s, char c) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = c;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}


void displayStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}


// a function to check if the expression is balanced
bool checkBalanced(char *exp) {
    Stack s;
    init(&s); 
    int len = strlen(exp) ; 
    for(int i = 0 ; i < len ; i++ ){
        displayStack(&s);
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&s,c);
            printf("%c", c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if(is_empty(&s)) {
                return false;
            } else { 
                char top = pop(&s);
                if ((c == '(' && top != ')') || (c == '{' && top != '}') || (c == '[' && top != ']')) { 
                    return false;
                }
            }
        }
    }
    return is_empty(&s);
}


int main() {
    char expr[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(expr, MAX_SIZE, stdin);
    if (checkBalanced(expr))
    {
        printf("The expression is balanced\n");
    }
    else
    {
        printf("The expression is not balanced\n");
    }
    return 0;
}
