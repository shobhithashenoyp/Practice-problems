#include<stdio.h>
int main()
{
    int n,i,largest,s_largest;
    int a[100];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    largest=0;
    s_largest =0;
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]>largest) 
        {
            s_largest = largest;
            largest = a[i];
        }
        else
        {
            if(a[i]>s_largest && a[i]!=largest)
            {
                s_largest = a[i];
            }
        }
    }
    if(s_largest==0)
    {
        printf("There is no second largest element\n");
    }
    else
    {
        printf("The second largest element is: %d\n",s_largest);
    }
    return 0;
}