/*
#include <stdio.h>
 
//function to count digits
int countDigits(int num)
{
    int count=0;
     
    if(num>0)
        count = 1 + countDigits(num/10);
    else
        return 0;
    
    return count;
}

int main()
{
    int number;
    int count=0;
     
    printf("Enter a positive integer number: ");
    scanf("%d",&number);
     
    count=countDigits(number);
     
    printf("Total digits in number %d is: %d\n",number,count);
     
    return 0;
}
*/