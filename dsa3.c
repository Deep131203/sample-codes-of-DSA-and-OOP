#include<stdio.h>
#define maxsize 10
void main()
{
    int arr[maxsize],i,num,power;
    float x,polysum;
    printf("enter the order of the ploynomial\n");
    scanf("%d",&num);
    printf("enter the value of x\n");
    scanf("%f",&x);
    printf("enter %d coefficients \n",num+1);
    for(i=0;i<=num;++i)
    {
        scanf("%d",&arr[i]);
    }
    polysum = arr[0];
    for(i=1;i<=num;++i)
    polysum = polysum*x+arr[i];
    power = num;
    printf("given polynomial is \n");
    for(i=0;i<=num;i++)
    {
        if(power<0)
        break;
        if(arr[i]>0)
        printf("+");
        else if(arr[i]<0)
        printf("-");
        else
        printf(" ");
        printf("%d x^%d",abs(arr[i]),power--);    
        }
}