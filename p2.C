#include <stdio.h>

int main()
{
    int a_insert(int a[], int n, int pos, int value);
    int a_delete(int a[], int n, int pos);
    void a_update(int a[], int n, int pos, int value);
    void a_display(int a[], int n);

    int n, i, a[100], pos, value, choice;

    printf("Enter size of array\n");
    if (scanf("%d", &n) != 1 || n < 0 || n > 100)
    {
        printf("Invalid array size. Enter a size from 0 to 100.\n");
        return 1;
    }

    printf("Enter array elements\n");

    for(i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Invalid array element.\n");
            return 1;
        }
    }

    do
    {
        printf("Enter choice\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Display\n");
        printf("Enter any other number to exit\n");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice.\n");
            return 1;
        }

        switch(choice)
        {
            case 1:
                printf("Enter position and value to insert\n");
                if (scanf("%d %d", &pos, &value) != 2)
                {
                    printf("Invalid position or value.\n");
                    return 1;
                }

                if(pos >= 1 && pos <= n + 1 && n < 100)
                    n = a_insert(a, n, pos, value);
                else if (n == 100)
                    printf("Array is full; cannot insert another element.\n");
                else
                    printf("Position must be between 1 and %d.\n", n + 1);

                break;

            case 2:
                printf("Enter position to delete\n");
                if (scanf("%d", &pos) != 1)
                {
                    printf("Invalid position.\n");
                    return 1;
                }

                if(pos >= 1 && pos <= n)
                    n = a_delete(a, n, pos);
                else
                    printf("Position must be between 1 and %d.\n", n);

                break;

            case 3:
                printf("Enter position and value to update\n");
                if (scanf("%d %d", &pos, &value) != 2)
                {
                    printf("Invalid position or value.\n");
                    return 1;
                }

                if(pos >= 1 && pos <= n)
                    a_update(a, n, pos, value);
                else
                    printf("Position must be between 1 and %d.\n", n);

                break;

            case 4:
                printf("Status of array\n");
                a_display(a, n);

                break;

            default:
                printf("Exiting.\n");
        }

    } while(choice >= 1 && choice <= 4);

    return 0;
}


int a_insert(int a[], int n, int pos, int value)
{
    int i;

    for(i = n - 1; i >= pos - 1; i--)
    {
        a[i] = a[i-1];
    }

    a[pos-1] = value;
    n = n + 1;

    return(n);
}


int a_delete(int a[], int n, int pos)
{
    int num, i;

    num = a[pos-1];

    printf("Element at position %d deleted is %d\n", pos, num);

    for(i = pos - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    n = n - 1;

    return(n);
}


void a_update(int a[], int n, int pos, int value)
{
    printf("Before update, the value at position %d is %d\n", pos, a[pos - 1]);

    a[pos-1] = value;

    printf("After update, the value at position %d is %d\n", pos, a[pos - 1]);

    
}


void a_display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}