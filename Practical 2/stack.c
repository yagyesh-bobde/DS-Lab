// Write a c program to implement stack using int array.
// use while loop and switch cases for user input and create a menu driven program.
// Create the stack structure and create two stacks and compare them

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

struct stack
{
    int top;
    int arr[MAX];
};

void push(struct stack *s, int data)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\n\nERROR: Could Not enter data");
        printf("Stack Underflow\n");
        return -1;
    }
    int data = s->arr[s->top];
    s->top--;
    return data;
}

void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}


int compareStacks()
{
    struct stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    int data1, data2;

    printf("Enter the elements of stack 1\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &data1);
        push(&s1, data1);
    }

    printf("Enter the elements of stack 2\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &data2);
        push(&s2, data2);
    }

    if (s1.top == -1 || s2.top == -1)
    {
        printf("Stacks are empty\n");
        return 0;
    }

    while (s1.top != -1 && s2.top != -1)
    {
        if (pop(&s1) != pop(&s2))
        {
            printf("Stacks are not equal\n");
            return 0;
        }
        s1.top--;
        s2.top--;
    }
    printf("Stacks are equal\n");
    return 1;
}

int main() { 
    int ch; 
    int data;
    struct stack s; 
    s.top = -1;

    while(1) {
        printf("Choose the operation to perform\n");
        printf("      1    -->    PUSH               \n");
        printf("      2    -->    POP               \n");
        printf("      3    -->    DISPLAY               \n");
        printf("      4    -->    Compare 2 stacks               \n");
        printf("      5    -->    EXIT           \n");
        printf("------------------------------------------\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: 
                printf("Enter the data to push\n");
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2: 
                data = pop(&s);
                if(data != -1) {
                    printf("Popped element is %d\n", data);
                }
                break;
            case 3: 
                display(&s);
                break;
            case 4:
                compareStacks();
                break;
            case 5: 
                exit(0);
        }
    }
    return 0;
}

