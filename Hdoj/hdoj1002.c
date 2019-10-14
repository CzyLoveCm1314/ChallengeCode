#include < stdio.h >
void main()
{
	int i,n;
	long long a, b;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%lld %lld", &a, &b);
		printf("Case %d:\n%lld + %lld = %lld\n\n", i, a, b, a + b);
	}
}