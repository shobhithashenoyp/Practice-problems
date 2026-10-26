#include<stdio.h>

void read_array(int a[], int n)
{
    printf("Enter the array elements: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }   
}

void bubble_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display_array(int a[], int n)
{
    printf("The sorted array is: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void main()
{
    int a[100],n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d",&n);
    if(n<1||n>100)
    {
        printf("Invalid array size\n");
        return;
    }
    read_array(a,n);
    bubble_sort(a,n);
    display_array(a,n);
}
