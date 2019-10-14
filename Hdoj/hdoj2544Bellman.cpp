#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define INF 0x3f3f3f3f
struct edge
{
	int from, to, cost;
}e[21000];
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)break;
		int dis[110];
		int i, j;
		for (i = 0; i < 110; i++) dis[i] = INF;
		dis[1] = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].cost);
			e[i + m].from = e[i].to;
			e[i + m].to = e[i].from;
			e[i + m].cost = e[i].cost;
		}
		m = m * 2;
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (dis[e[j].to]>dis[e[j].from] + e[j].cost) dis[e[j].to] = dis[e[j].from] + e[j].cost;
			}
		}
		printf("%d\n", dis[n]);
	}
	return 0;
}