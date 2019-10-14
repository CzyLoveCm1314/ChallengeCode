#include<stdio.h> 

int main(void)
{
	int a, b, n,i;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}