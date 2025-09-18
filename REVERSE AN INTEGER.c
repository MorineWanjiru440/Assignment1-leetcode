#include <stdio.h>
int main()
{
int num, reverse = 0, remainder;
printf("Enter the num; ");
scanf("%d",&num);
while (num!=0)
	remainder = num%10;
reverse=reverse * 10 + remainder;
num=num/10;
printf("The reverse is = %d",reverse);
return 0;
}

