#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//reverse, convert to postfix, reverse again
#define MAX 100

char infix[MAX], stack[MAX], postfix[MAX], prefix[MAX];
int top = -1;
char rev[MAX];

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

void reverseStr(char a[MAX], char b[MAX])
{
    int n = strlen(a);
    int i = 0, j = 0;

    while (a[i] != '\0')
    {
        b[n-1-j] = a[i];
        i++;
        j++;
    }

    b[n] = '\0';

    for (int i = 0; i < strlen(b); i++)
    {
        if(b[i] == '(')
        {
            b[i] = ')';
        }
        else if (b[i] == ')')
        {
            b[i] = '(';
        }
    }
}

void pref()
{
    int i, j = 0;
    char symbol, next;

    for (i = 0; i < strlen(rev); i++)
    {
        symbol = rev[i];

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

void preEval()
{
    int i = 0, o1, o2;
    char symbol;

    for (i = strlen(prefix)-1; i >= 0; i--)
    {
        symbol = prefix[i];

        switch(symbol)
        {
        case '+':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o1 + o2)+'0');
            break;
        case '-':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o1 - o2)+'0');
            break;
        case '*':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o1 * o2)+'0');
            break;
        case '/':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o1 / o2)+'0');
            break;
        case '^':
            o1 = pop() - '0';
            o2 = pop() - '0';
            push((o1 ^ o2)+'0');
            break;
        default:
            push(symbol);
            break;
        }
    }

    printf("\nThe result is: %c", stack[top]);
}


void main()
{
    printf("Enter Infix Expression: ");
    gets(infix);

    reverseStr(infix, rev);

    pref();

    reverseStr(postfix, prefix);

    printf("\n");

    printf("Equivalent Prefix Expression is: ");
    for (int i = 0; i < strlen(prefix); i++)
    {
        printf("%c", prefix[i]);
    }

    preEval();
}
