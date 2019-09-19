#include<cstdio>
#include<iostream>

using namespace std;
#define MAXN 60000
int fa[MAXN], ran[MAXN];
void init()
{
	int i;
	for (i = 0; i < MAXN; i++)
	{
		fa[i] = i;
		ran[i] = 0;
	}
}

int find(int x)
{
	if (fa[x] == x) return x;
	else
	{
		return fa[x] = find(fa[x]);
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (ran[x] < ran[y]) fa[x] = y;
	else
	{
		fa[y] = x;
		if (ran[x] == ran[y]) ran[x]++;
	}
}
int main()
{

	int m, n,c=1;
	while (scanf("%d%d", &n, &m) != EOF && (n + m))
	{
		init();
		int i, j,a,b,ans=0;
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
			for (int i = 1; i <= n; i++) if (i == find(i)) ans++;		
			printf("Case %d: %d\n", c++, ans);
	}
	return 0;
}