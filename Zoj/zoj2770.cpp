#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 1000 + 10;
const int MAXM = 10000 + 10;
const int INF = -100000000;
struct edge
{
	int to;
	int val;
	int next;
}e[MAXM];

int head[MAXN], len, n, m, c, dis[MAXN];
void add(int from, int to, int val)
{
	e[len].to = to;
	e[len].val = val;
	e[len].next = head[from];
	head[from] = len++;
}


bool spfa()
{
	for (int i = 0; i <= n; i++)
		dis[i] = INF;

	bool vis[MAXN] = { 0 };
	int cnt[MAXN] = { 0 };
	queue<int> q;
	dis[0] = 0;
	vis[0] = true;
	cnt[0] = 1;
	q.push(0);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		vis[cur] = false;

		for (int i = head[cur]; i != -1; i = e[i].next)
		{
			int id = e[i].to;
			if (dis[cur] + e[i].val > dis[id])
			{
				dis[id] = dis[cur] + e[i].val;
				if (!vis[id])
				{
					cnt[id]++;
					if (cnt[cur] > n)
						return false;
					vis[id] = true;
					q.push(id);
				}
			}
		}
	}
	return true;
}


int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		len = 0;
		memset(head, -1, sizeof(head));

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &c);
			add(i, i - 1, -c);
			add(i - 1, i, 0);
			add(0, i, 0);
		}
		for (int i = 0; i<m; i++)
		{
			int from, to, val;
			scanf("%d%d%d", &from, &to, &val);
			add(from - 1, to, val);
		}
		if (spfa())
			printf("%d\n", dis[n]);
		else
			puts("Bad Estimations");
	}

	return 0;
}
