#include <cstdio>
#define maxn 1000005
int num[maxn];
int pre[maxn];
int max(int a, int b)
{
	return a > b ? a : b;
}

int DP(int n, int m)
{
	for (int i = 1; i <= m; ++i)
	{
		int tmp = 0;
		for (int k = 1; k <= i; ++k) tmp += num[k];
		pre[n] = tmp;
		for (int j = i + 1; j <= n; ++j)
		{
			tmp = max(pre[j - 1], tmp) + num[j];
			pre[j - 1] = pre[n];
			pre[n] = max(pre[n], tmp);
		}
	}
	return pre[n];
}

int main()
{
	int n, m;
	while (scanf("%d%d", &m, &n)!=EOF)
	{
		int i;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			pre[i] = 0;
		}
		printf("%d\n", DP(n, m));
	}
	return 0;
}