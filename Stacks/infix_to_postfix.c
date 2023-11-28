#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX-1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("stack underflow");
        exit(1);
    }

    char c = stack[top];
    top--;
    return c;

}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int precedence(char symbol)
{
    switch(symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}



void post()
{
    int i, j = 0;
    char symbol, next;

    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        switch(symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while((next = pop()) != '(')
            {
                postfix[j++] = next;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
            break;
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void print()
{
    int i = 0;
    printf("\nThe Postfix expression is: ");
    while(postfix[i])
    {
        printf("%c\n  ",postfix[i++]);
    }
    printf("\n");
}

void posteval()
{
    int i = 0, o1, o2;
    char symbol;

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];

        switch(symbol)
        {
        case '+':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o2 + o1)+'0');
            break;
        case '-':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o2 - o1)+'0');
            break;
        case '*':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o2 * o1)+'0');
            break;
        case '/':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o2 / o1)+'0');
            break;
        case '^':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o2 ^ o1)+'0');
            break;
        default:
            push(symbol);
            break;
        }
    }

    printf("The result is: %c", stack[top]);
}

int main()
{
    printf("Enter Infix Expression: ");
    gets(infix);

    post();

    print();

    //int x = (int)postfix[0];
    //printf("%d", x);
    posteval();
    return 0;
}
