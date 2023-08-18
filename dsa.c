#include<stdio.h>
int main()
{
    int arr[10],n,i;
    for(i=0;i<10;++i)
    {
        printf("enter an element");
        scanf("%d",&n);
        arr[i] = n;
    }
    for(i=2;i<10;++i)
    {
        arr[i] = arr[i+1];
    }
    for(i=4;i<8;++i)
    {
        arr[i] = arr[i+1];
    }
    printf("%d",arr[4]);
    return 0;
    }
    
