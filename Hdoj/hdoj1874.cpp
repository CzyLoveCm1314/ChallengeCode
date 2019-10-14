#include<iostream>
#include<algorithm>
using namespace std;
int dis[1200];
#define INF 0x3f3f3f3f
struct edge
{
	int from, to, cost;
} e[2500];
int main()
{
	int n, m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{	
		int i, j;
		for (i = 0; i < n; i++)
		{
			dis[i] = INF;
		}
		for (i = 0; i < m; i++)
		{
			int fr, to, cost;
			scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].cost);
			e[i + m].from = e[i].to;
			e[i + m].to = e[i].from;
			e[i + m].cost = e[i].cost;
		} 
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		dis[n1] = 0;
		m = m * 2;
		int flag;
		while (true)
		{
			bool update = false;
			for (int i = 0; i < m; i++)
			{
				edge es = e[i];
				if (dis[es.from] != INF&&dis[es.to]>dis[es.from] + es.cost)
				{
					dis[es.to] = dis[es.from] + es.cost;
					update = true;
				}
			}
			if (!update) break;
		}
		printf("%d\n", dis[n2] ==INF ? -1 : dis[n2]);
	}

	return 0;
}