#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int MIN(int a, int b)
{
	if (a > b)return b;
	else return a;
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)break;
		int a[110][110];
		int i, j,k;
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n; j++)
			{
				if (i != j)a[i][j] = INF;
				else a[i][j] = 0;
			}
		for (i = 0; i < m; i++)
		{
			int from, to, cost;
			scanf("%d%d%d", &from, &to, &cost);
			a[from][to] = a[to][from] = cost;
		}
		
		for (k = 1; k<=n; k++)
			for (i = 1; i<=n; i++)
				for (j = 1; j<=n; j++)
					a[i][j] = MIN(a[i][j], a[i][k] + a[k][j]);
		printf("%d\n", a[1][n] == INF ? -1 : a[1][n]);

	}
	return 0;
}