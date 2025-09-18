#include <stdio.h>
int main()
{
	int num, remainder, reverse = 0;
	printf("Enter the num; ");
	scanf( "%d", &num);
	while (num != 0)
	{
		remainder = num % 10;
	reverse = reverse * 10 + remainder;
	num = num / 10;
	}
	printf("The reverse = %d\n", reverse);
	if (num == reverse)
	{
		printf("True");
	}
	else
	{
		printf("False");
	}

return 0;
}
