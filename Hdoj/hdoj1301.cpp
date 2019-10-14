#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
int n;
int a[maxn][maxn];

int prim() {
	bool vis[maxn];
	int lowcost[maxn];
	for (int i = 0; i < n; i++) {
		vis[i] = false;
		lowcost[i] = a[0][i];
	}
	int ans = 0;
	int k = -1;
	lowcost[0] = 0;
	vis[0] = true;
	for (int i = 1; i <= n - 1; i++) {
		int min = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && lowcost[j]<min) {
				min = lowcost[j];
				k = j;
			}
		}
		if (min == INF) break;
		vis[k] = true;
		ans += lowcost[k];
		for (int i = 0; i < n; i++) {
			if (!vis[i] && lowcost[i]>a[k][i])
				lowcost[i] = a[k][i];
		}
	}
	return ans;
}
int main() {
	while (~scanf("%d", &n)&&n) {
		memset(a, 0x3f, sizeof(a));
		getchar();
		char c1, c2;
		int cnt, temp;
		for (int i = 0; i < n - 1; i++) {
			scanf("%c%d", &c1, &cnt);
			for (int j = 0; j < cnt; j++) {
				getchar();
				scanf("%c%d", &c2, &temp);
				a[c1 - 'A'][c2 - 'A'] = a[c2 - 'A'][c1 - 'A'] = temp;
			}
			getchar();
		}
		printf("%d\n", prim());
	}
	return 0;
}