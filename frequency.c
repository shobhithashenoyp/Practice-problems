#include<stdio.h>
int main()
{
    int a[100],n,i,j,count;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        count=1;
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            
            }
        }
        printf("Element %d occurs %d times\n", a[i], count);
    }
}
