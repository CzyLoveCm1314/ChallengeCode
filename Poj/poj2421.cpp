#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];
int T[maxn][maxn];
int prim(int n) {
	int lowcost[maxn];
	bool vis[maxn];
	memset(lowcost, 0x3f, sizeof(lowcost));
	memset(vis, false, sizeof(vis));

	int sum = 0;
	for (int j = 0; j < n; j++) lowcost[j] = G[0][j];
	int k = 0;
	vis[0] = true;
	for (int i = 1; i <= n - 1; i++) {
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
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &G[i][j]);
	}
	int k;
	scanf("%d", &k);
	int a, b;
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &a, &b);
		G[a-1][b-1] = G[b-1][a-1] = 0;
	}
	int sum = prim(n);
	printf("%d\n", sum);

	return 0;
}