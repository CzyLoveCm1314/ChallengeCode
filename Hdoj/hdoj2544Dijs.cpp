#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
int G[203][203];
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{

		if (n == 0 && m == 0) break;
		int i, j;
		for (i = 0; i<=n; i++)
			for (j = 0; j<=n; j++)
				G[i][j] = (i == j ? 0 : INF);
		while (m--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if (G[u][v]>w) G[u][v] = G[v][u] = w;
		}
		int vis[210] = { 0 };
		int dis[210];
		for (i = 0; i<=n; i++)dis[i] = G[1][i];
		dis[1] = 0;
		vis[1] = true;
		for (i = 1; i < n; i++)
		{
			int k = -1;
			for (j = 1; j<=n; j++)
				if (!vis[j] && (k == -1 || dis[k]>dis[j]))
					k = j;
			if (k == -1) break;
			vis[k] = true;
			for (j = 1; j<=n; j++)
				if (!vis[j] && dis[j]>dis[k] + G[k][j])
					dis[j] = dis[k] + G[k][j];
		}
		printf("%d\n", dis[n]);
	}
	return 0;
}