#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 110;
int n, SodierSum, Gain[N][N], bug[N], brain[N];
vector<int> g[N];
bool visited[N];

void init()
{
	memset(visited, false, sizeof(visited));
	memset(Gain, 0, sizeof(Gain));
	for (int i = 0; i <= n; ++i) g[i].clear();
}
void dfs(int root)
{
	visited[root] = true;
	int size = g[root].size();
	int cost = (bug[root] + 19) / 20;
	if (SodierSum < cost) return;
	for (int i = cost; i <= SodierSum; ++i) Gain[root][i] = brain[root];
	for (int i = 0; i<size; ++i)
	{
		int son = g[root][i];
		if (visited[son]) continue;
		dfs(son);
		for (int sodier = SodierSum; sodier >= cost; sodier--)
		{
			for (int send = 1; send <= sodier - cost; send++)
				if (sodier - send >= cost)
					Gain[root][sodier] = max(Gain[root][sodier], Gain[root][sodier - send] + Gain[son][send]);
		}
	}
}
int main()
{
	int x, y;
	while (scanf("%d %d", &n, &SodierSum) !=EOF)
	{
		if (n == -1 && SodierSum == -1) break;
		for (int i = 1; i <= n; ++i) scanf("%d%d", &bug[i], &brain[i]);
		init();
		for (int root = 1; root<n; root++)
		{
			scanf("%d %d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if (SodierSum == 0)
		{
			printf("0\n");
			continue;
		}
		else
		{
			dfs(1);
			cout << Gain[1][SodierSum] << endl;
		}

	}
	return 0;
}