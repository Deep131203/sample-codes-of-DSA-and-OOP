#include<stdio.h>
#define ROWS 3
#define COLS 4
void printOneDArray(int oneD[],int num_rows,int num_cols)
{
    int i;
    int j;
    printf("contents of the one dimensional array:\n");
    for(i=0;i<num_rows;i++)
    {
        for(j=0;j<num_cols;j++)
        {
            int oneD_index = i*num_cols+j;
            printf("%d",oneD[oneD_index]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j;
    int arr[ROWS][COLS] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int oneD[ROWS*COLS];
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            int oneD_index=i*COLS+j;
            oneD[oneD_index]=arr[i][j];
        }
    }
    printOneDArray(oneD,ROWS,COLS);
    return 0;
}
