#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<functional>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1100;
int n, m;
int a[maxn][maxn];
bool vis[maxn];
int dis[maxn];

int dijkstra(int s, int e) {
	for (int i = 1; i <= n; i++) dis[i] = a[s][i];
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	vis[s] = 1;
	for (int i = 1; i < n; i++) {
		int k = -1;
		int m = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && dis[j]> m) { //寻找最大载货量的。
				k = j;
				m = dis[k];
			}
		}
		if (k != -1) {
			vis[k] = 1;
			for (int j = 1; j <= n; j++) { //将最小的权值作为最大载货量
				if (!vis[j] && dis[j] < min(dis[k], a[k][j]))
					dis[j] = min(dis[k], a[k][j]);
			}
		}
	}
	return dis[e];
}
int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = i == j ? 0 : -1;
		int x, y, z;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			a[x][y] = a[y][x] = z;
		}
		printf("Scenario #%d:\n", k);
		printf("%d\n\n", dijkstra(1, n));
	}

	return 0;
}