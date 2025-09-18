#include <stdio.h>
int main()
{
	int arr[100], n, i, j, temp;
	printf("Enter the number on elements");
	scanf("%d", &n);
	printf("Enter %d elements\n", n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	printf ("array in ascending order\n:");
	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

