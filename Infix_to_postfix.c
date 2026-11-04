#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
char stack[max];
int top = -1;

void push(char ch)
{
    if (top == max - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char symbol)
{
    switch (symbol)
    {
       case '+': case '-': return 2;
       case'%': case '*': case '/': return 3;
       case '^':  case '&': case'$': return 4;
       case '(' : return 0;
       case '#': return -1;
       default: return -1;

    }
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;
    push('#'); // Push a sentinel value to the stack

    while ((symbol = infix[i++]) != '\0')
    {
        if (isalnum(symbol)) // If the symbol is an operand
        {
            postfix[j++] = symbol; // Add it to the postfix expression
        }
        else if (symbol == '(') // If the symbol is '(', push it onto the stack
        {
            push(symbol);
        }
        else if (symbol == ')') // If the symbol is ')', pop and output from the stack until an '(' is encountered
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' from the stack
        }
        else // If the symbol is an operator
        {
            while (precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol); // Push the current operator onto the stack
        }
    }

    while (stack[top] != '#') // Pop all remaining operators from the stack
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}
 int main()
{
    char infix[max], postfix[max];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}