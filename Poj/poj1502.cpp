#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 110;
const int inf = 0x3f3f3f3f;
int n;
int a[maxn][maxn];
int dis[maxn];
bool vis[maxn];

void dijkstra() {
	for (int i = 1; i <= n; i++) dis[i] = a[1][i];
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		int k = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (k == -1 || dis[k]>dis[j]))k = j;
		}
		if (k == -1)break;
		vis[k] = 1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && dis[j]>dis[k] + a[k][j]) 
				dis[j] = dis[k] + a[k][j];
		}
	}
	int ans = -1;
	for (int i = 2; i <= n; i++)ans = max(ans, dis[i]);
	printf("%d\n", ans);
}

int main() {
	char op[20];
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				if (i == j) a[i][j] = 0;
				else a[i][j] = inf;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				scanf("%s", op);
				if (op[0] != 'x') a[i][j] = a[j][i] = atoi(op);
			}
		}
 		dijkstra();
	}
	return 0;
}