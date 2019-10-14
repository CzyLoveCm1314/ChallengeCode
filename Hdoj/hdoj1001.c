#include<stdio.h>

void main()
{
	int n, i, sum;
	sum = 0;
	while (scanf_s("%d", &n) != EOF)
	{
		sum = 0;
		for (i = 1; i <= n; i++)
			sum = sum + i;
		printf("%d\n\n", sum);

	}
}