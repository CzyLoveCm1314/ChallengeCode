#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 600;
const int INF = 0x3f3f3f3f;
int a[maxn][maxn];
int n;
bool vis[maxn];
int mincost[maxn];

int prim() {
	for (int i = 0; i < n; i++) {
		mincost[i] = a[0][i];
		vis[i] = false;
	}
	vis[0] = true;
	mincost[0] = 0;
	int ans = 0;
	int maxe = -1;
	while (true) {
		int v = -1;
		for (int u = 0; u < n; u++) {
			if (!vis[u] && (v == -1 || mincost[u] < mincost[v]))v = u;
		}
		if (v == -1)break;
		vis[v] = true;
		ans += mincost[v];
		if (mincost[v] > maxe) maxe = mincost[v];
		for (int u = 0; u < n; u++) {
			mincost[u] = min(mincost[u], a[v][u]);
		}
	}
	return maxe;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {

		scanf("%d", &n);
		for (int i = 0; i< n; i++){
			for (int j = 0; j< n; j++)
				scanf("%d", &a[i][j]);
		}
		printf("%d\n", prim());
	}
	return 0;
}