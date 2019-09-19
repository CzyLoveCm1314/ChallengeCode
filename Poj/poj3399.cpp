#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 120
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		int i,l1,l2,l3;
		l1 = l2 = l3 = 1;
		int a[MAXN] = { 0 }, f[MAXN] = { 0 },z[MAXN] = { 0 };
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] >= 0) z[l2++] = a[i];
			else  f[l1++] = a[i];
		}
		sort(z + 1, z + l2);
		sort(f + 1, f + l1);
		int ans[MAXN] = { 0 };
		if (k % 2 == 1)
		{
			if (l2 > 1) ans[l3++] = z[--l2];
			else
			{
				for (i = l1 - 1; i > l1  - k; i--)
				{
					printf("%d ", f[i]);
				}
				printf("%d\n", f[i]);
				continue;
			}
		}
		int l4 = 1;
		for (i = 0; i < k / 2; i++)
		{
			int t1, t2;
			t1 = t2 = -3001;
			if (l2 == 1 && l1 - l4 == 1)
			{
				ans[l3++] = z[--l2];
				ans[l3++] = f[++l4];
			}
			else
			{
				if (l2 > 1)
					t1 = z[l2 - 1] *z[l2 - 2];
				if (l1- l4 > 1)
					t2 = f[l4] * f[l4 + 1];
				if (t1 > t2)
				{
					ans[l3++] = z[--l2];
					ans[l3++] = z[--l2];
				}
				else
				{
					ans[l3++] = f[l4++];
					ans[l3++] = f[l4++];
				}
			}
		}
		sort(ans + 1, ans  + l3);
		for (i = l3-1 ; i > 1; i--)
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[1]);
	}
	return 0;
}