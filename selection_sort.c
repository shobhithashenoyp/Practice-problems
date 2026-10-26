#include<stdio.h>
void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

void read_array(int a[], int n)
{
    printf("Enter the array elements: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
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
    selection_sort(a,n);
    display_array(a,n);
}