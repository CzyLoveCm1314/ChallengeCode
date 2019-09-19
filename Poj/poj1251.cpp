#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define maxn 300
#define INF 0x3f3f3f3f
int G[maxn][maxn];

int prim(int n) {
	int lowcost[maxn];
	bool vis[maxn];
	memset(lowcost, 0x3f, sizeof(lowcost));
	memset(vis, false, sizeof(vis));

	int sum = 0;
	for (int j = 0; j < n; j++) lowcost[j] = G[0][j];
	int k = 0;
	vis[0] = true;
	for (int i = 1;i <= n-1; i++) {
		int min = INF;
		for (int j = 0; j < n; j++) {
			if (min> lowcost[j])
				if (!vis[j]) {
					k = j;
					min = lowcost[j];
				}
		}
		vis[k] = true;
		sum += lowcost[k];
		for (int j = 0; j < n; j++)
			if (G[k][j] < lowcost[j] && !vis[j]) lowcost[j] = G[k][j];
	}
	return sum;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		memset(G, 0x3f, sizeof(G));
		char ch,t;
		int cnt,w;
		for (int i = 1; i <= n - 1; i++) {
			cin >> ch >> cnt;
			for (int j = 1; j <= cnt; j++) {
				cin >> t >> w;
				G[ch - 'A'][t - 'A'] = G[t - 'A'][ch - 'A'] =w;
			}
		}
		int sum = prim(n);
		printf("%d\n", sum);
	}
	return 0;
}