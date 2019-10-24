
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int inf = 1000000000;
const int maxn = 1000;
int G[maxn][maxn];
int num[maxn], w[maxn], a[maxn];
bool vis[maxn];
int dis[maxn];
int n, m, c1, c2;

void dijkstra() {
	for (int i = 0; i < n; i++) dis[i] = G[c1][i], num[i] = 1;
	memset(vis, false, sizeof(vis));
	memset(w, 0, sizeof(w));
	vis[c1] = 1;
	dis[c1] = 0;
	num[c1] = 1;
	w[c1] = a[c1];
	for (int i = 0; i < n; i++) {
		int MINLEN = inf;
		int k = -1;
		for (int j = 0; j<n; j++) {
			if (!vis[j] && dis[j]<MINLEN) {
				k = j;
				MINLEN = dis[j];
			}
		}
		w[k] = max(w[c1] + a[k], w[k]);
		if (k == -1) return;
		vis[k] = true;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && G[k][j] != inf) {
				if (dis[j] > dis[k] + G[k][j]) {
					dis[j] = dis[k] + G[k][j];
					num[j] = num[k];
					w[j] = w[k] + a[j];
				}
				else if (dis[j] == dis[k] + G[k][j]) {
					num[j] += num[k];
					if (w[j] < w[k] + a[j]) {
						w[j] = w[k] + a[j];
					}
				}
			}
		}
	}
}


int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int u, v, c;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		G[u][v] = c;
		G[v][u] = c;
	}
	dijkstra();
	printf("%d %d\n", num[c2], w[c2]);
	return 0;
}

