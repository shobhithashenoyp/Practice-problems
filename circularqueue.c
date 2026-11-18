#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue()
{
    int item;
    if((rear+1)%MAX==front)
    {
        printf("CircularQueue is full\n");
        return;
    }
    else 
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&item);
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%MAX;
        queue[rear]=item;
        printf("Element inserted successfully\n");
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Circular Queue is empty\n");
    }
    else
    {
        printf("Deleted element is: %d\n",queue[front]);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
}
void display()
{
    int i;
   if(front==-1)
   {
    printf("Circular queue is empty \n");
   }
   else
   {
    printf("Elements in circular queue are: ");
    i=front;
    while(1)
    {
        printf("%d",queue[i]);
        if(i==rear)
        {
            break;
        }
        i=(i+1)%MAX;
    }
    printf("\n");
   }
}
void main()
{
    int choice;
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }  while(choice!=4);
} 
    
