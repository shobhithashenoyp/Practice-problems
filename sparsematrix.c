#include<stdio.h>
# define MAX 100
int main() 
{
    int a[MAX][MAX];
    int tri[MAX][3],trans[MAX][3],rows,cols,i,j,indexoftranspose;;
    int nonzero=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&rows,&cols);
    printf("Enter the elements of the matrix: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
            {
                nonzero++;
                tri[nonzero][0]=i;
                tri[nonzero][1]=j;
                tri[nonzero][2]=a[i][j];
            }
        }
    }
    printf("Sparse matrix representation: \n");
    for(i=1;i<=nonzero;i++)
    {
        printf("%d %d %d\n", tri[i][0], tri[i][1], tri[i][2]);
    }
    printf("Transpose of the sparse matrix: \n");
    trans[0][0]=cols;
    trans[0][1]=rows;
    trans[0][2]=nonzero;
    indexoftranspose=1;
    for(i=0;i<cols;i++)
    {
        for(j=1;j<=nonzero;j++)
        {
            if(tri[j][1]==i)
            {
                trans[indexoftranspose][0]=tri[j][1];
                trans[indexoftranspose][1]=tri[j][0];
                trans[indexoftranspose][2]=tri[j][2];
                indexoftranspose++;
            }
        }
    }
    printf("Transpose of the sparse matrix: \n");
    for(i=0;i<indexoftranspose;i++)
    {
        printf("%d %d %d\n", trans[i][0], trans[i][1], trans[i][2]);
    }
}