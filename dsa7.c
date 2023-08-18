#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int row;
    int col;
    int value;
}Triplet;
void addSparseMatrices(Triplet*matrix1,int size1,Triplet*matrix2,int size2,Triplet**result,int*resultSize)
{
    int i=0,j=0,k=0;
    *resultSize=0;
    *result=(Triplet*)malloc((size1+size2)*sizeof(Triplet));
    while(i<size1 && j<size2)
    {
        if(matrix1[i].row<matrix2[j].row||(matrix1[i].row==matrix2[j].row && matrix1[i].col<matrix2[j].col))
        {
            (*result)[k]=matrix1[i];
            i++;
        }
        else if(matrix1[i].row>matrix2[j].row||(matrix1[i].row==matrix2[j].row && matrix1[i].col>matrix2[j].col))
        {
            (*result)[k]=matrix2[j];
            j++;
        }
        else
        {
            (*result)[k]=matrix1[i];
            (*result)[k].value+=matrix2[j].value;
            i++;
            j++;
        }
        if((*result)[k].value!=0)
        {
            k++;
        }
    }
    while(i<size1)
    {
        (*result)[k]=matrix1[i];
        i++;
        k++;
    }
    while(j<size2)
    {
        (*result)[k]=matrix2[j];
        j++;
        k++;
    }
    *resultSize = k;
}
int main()
{
    int size1,size2,resultSize,i;
    printf("enter the number of non zero elements in the first matrix:");
    scanf("%d",&size1);
    Triplet*matrix1=(Triplet*)malloc(size1*sizeof(Triplet));
    printf("enter the row,column,and value for each non zero element in the first matrix:\n");
    for(i=0;i<size1;i++)
    {
        scanf("%d%d%d",&matrix1[i].row,&matrix1[i].col,&matrix1[i].value);
    }
    printf("enter the number of non zero elements inn the second matrix:");
    scanf("%d",&size2);
    Triplet*matrix2=(Triplet*)malloc(size2*sizeof(Triplet));
    printf("enter the row,column,and value for each non zero element in the second matrix:\n");
    for(i=0;i<size2;i++)
    {
        scanf("%d%d%d",&matrix2[i].row,&matrix2[i].col,&matrix2[i].value);
    }
    Triplet*result;
    addSparseMatrices(matrix1,size1,matrix2,size2,&result,&resultSize);
    printf("result matrix(row col value):\n");
    for(i=0;i<resultSize;i++)
    {
        printf("%d%d%d\n",result[i].row,result[i].col,result[i].value);
    }
    free(matrix1);
    free(matrix2);
    free(result);
    return 0;
}
