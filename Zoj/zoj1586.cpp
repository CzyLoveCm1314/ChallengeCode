#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1010;
int G[maxn][maxn];
int a[maxn];

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
	int t, n, temp;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(G, 0x3f, sizeof(G));
		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &temp);
				G[i][j] = temp+a[i]+a[j];
			}
		int sum = prim(n);
		printf("%d\n", sum);
	}
	return 0;
}