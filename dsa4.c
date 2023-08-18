#include<stdio.h>
void countNonZeroElements(int rows,int cols,int matrix[rows][cols])
{
    int count,i,j;
    printf("number of non zero elements in each row:\n");
    for(i=0;i<rows;i++)
    {
        count = 0;
        for(j=0;j<cols;j++)
        {
            if(matrix[i][j]!=0)
            {
                count++;
            }
        }
    printf("row %d %d non zero elements\n",i,count);
    }
}
int main()
{
    int rows,cols,i,j;
    printf("enter the number of rows in the sparse matrix:");
    scanf("%d",&rows);
    printf("enter the number of columns in the sparse matrix:");
    scanf("%d",&cols);
    int matrix[rows][cols];
    printf("enter the elements of the sparse matrix:\n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    countNonZeroElements(rows,cols,matrix);
    return 0;
}

