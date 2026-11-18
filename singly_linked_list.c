#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node *head = NULL;
/* Insert at the beginning */
void insertAtBeginning()
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Node inserted at the beginning successfully\n");
}
/* Insert at the end */
void insertAtEnd()
{
    struct Node *newnode, *temp;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Node inserted at the end successfully\n");
}
/* Insert at a specific position */
void insertAtPosition()
{
    struct Node *newnode, *temp;
    int pos,i;
    printf("Enter the position to insert the node: ");
    scanf("%d", &pos);
    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if(pos == 1)
    {
        insertAtBeginning();
        return;
    }
    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted at the specified position successfully\n");
}
/* Delete at the beginning */
void deleteAtBeginning()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning successfully\n");
}
/* Delete at the end */
void deleteAtEnd()
{
    struct Node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Node deleted from the end successfully\n");
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted from the end successfully\n");
}
/* Delete at a specific position */
void deleteAtPosition()
{
    struct Node *temp, *prev;
    int pos, i;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);
    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(pos == 1)
    {
        deleteAtBeginning();
        return;
    }
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from the specified position successfully\n");
}
/*Display the list*/
void displayList()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("The list is: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
/*Main function*/
int main()
{
    int choice;
    do
    {
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 8);
    return 0;
}