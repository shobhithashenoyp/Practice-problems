#include<stdio.h>
#define size 5
int stack[size], top = -1;
void push();
void pop();
void display();
void main()
{
    int choice;
    for(;;)
    {
        printf("1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Exiting...\n");
                return;
        }
    }
}
void push()
{
    int value;
    if(top == size -1)
    {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&value);
    stack[++top]=value;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("The popped element is %d\n",stack[top--]);

}
void display()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack are: \n ");
    for(int i = top; i >= 0; i--)
    {
        printf("%d \n", stack[i]);
    }
    printf("\n");
}
