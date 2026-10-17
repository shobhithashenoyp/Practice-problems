#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} sparse;

int main()
{
    void generate_sparse(int a[][10], int m, int n,sparse s[]);
    void print_sparse(sparse s[]);

    int a[10][10], m, n;
    int s[100][3];

    printf("Enter the order of matrix\n");
    scanf("%d%d", &m, &n);

    printf("Enter the sparse matrix\n");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    generate_sparse(a, m, n, s);
    print_sparse(s);
    return 0;
}

void generate_sparse(int a[][10], int m, int n, sparse s[])
{
    int i, j, count = 0;

    s[0].row = m;
    s[0].col = n;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
            {
                count++;

                s[count].row = i;
                s[count].col = j;
                s[count].value = a[i][j];
            }
        }
    }

    s[0].value = count;

  
}

void print_sparse(sparse s[])
{
    int i;

    printf("Tuple sparse\n");
    printf("Row\tcol\tvalue\n");

    for(i = 1; i <= s[0].value; i++)
    {
        printf("%d\t%d\t%d\n",
               s[i].row, s[i].col, s[i].value);
    }

    printf("\n");

 
}