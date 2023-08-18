#include<stdio.h>
#include<string.h>
#define MAX_DIGITS 1000
//Function to add two  large numbers
char*addLargeNumbers(const char*num1,const char*num2)
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    //reverse the numbeers to make addition easier
    char revNum1[MAX_DIGITS],revNum2[MAX_DIGITS];
    for(int i=0;i<len1;i++)
    {
        revNum1[i]=num1[len1-1-i]-'0';
    }
    for(int i=0;i<len2;i++)
    {
        revNum2[i]=num2[len2-1-i]-'0';
    }
    //find the length of the result
     int lenResult=(len1>len2)? len1:len2;
     int carry = 0;
     int sum[MAX_DIGITS];
     //perform addition
     for(int i=0;i<lenResult;i++)
     {
        int digit1=(i<len1)? revNum1[i]:0;
        int digit2=(i<len2)? revNum2[i]:0;
        int total=digit1+digit2+carry;
        sum[i]=total%10;
        carry=total/10;
     } 
     //handle the last carry if any
     if(carry){
        sum[lenResult]=carry;
        lenResult++;
     }
     //reverse the result to get the correct output 
     static char result[MAX_DIGITS +1];
     for(int i=0;i<lenResult;i++)
     {
        result[i]=sum[lenResult-1-i]+'0';
     }
     result[lenResult]='\0';
     return result;
}
int main()
{
   char num1[MAX_DIGITS],num2[MAX_DIGITS];
   //Input the two large numbers as strings
   printf("enter the first large number:");
   scanf("%s",num1);
   printf("enter the second large number:");
   scanf("%s",num2);
   //Add the two large numbers
   char*result = addLargeNumbers(num1,num2);
   //Display the result
   printf("result of addition :%s\n",result);
   return 0;
}
