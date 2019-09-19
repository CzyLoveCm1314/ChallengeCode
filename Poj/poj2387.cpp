#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t, n;
int a[2100][2100];
int dis[2100];
bool vis[2100];

int dijkstra(int s, int e) {
	for (int i = 1; i <= n; i++) dis[i] = a[s][i];
	vis[s] = 1;
	dis[s] = 0;
	for (int i = 1; i < n; i++) {
		int k = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (k == -1 || dis[k]>dis[j])) {
				k = j;
			}
		}
		if (k == -1)break;
		vis[k] = 1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && dis[j] > dis[k] + a[k][j]) {
				dis[j] = dis[k] + a[k][j];
			}
		}
	}
	return dis[e];
}

int main() {
	scanf("%d%d", &t, &n);
		memset(a, 0x3f, sizeof(a));
		int u, v, c;
		for (int i = 1; i <= t; i++) {
			scanf("%d%d%d", &u, &v, &c);
			if (c < a[u][v]) {
				a[u][v] = a[v][u] = c;
			}
		}
		printf("%d\n", dijkstra(n,1));
	return 0;
}