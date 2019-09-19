#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 2000 + 100;
int fa[maxn<<1], ra[maxn<<1];

void init() {
	for (int i = 1; i < maxn<<1; i++) {
		ra[i] = 0;
		fa[i] = i;
	}
}

int find(int x) {
	while (x != fa[x]) {
		x = fa[x];
	}
	return x;
}
void unite(int x, int y) {
	int r1 = find(x);
	int r2 = find(y);
	if (r1 == r2) return;
	if (ra[r1] < ra[r2])fa[r1] = r2;
	else {
		fa[r2] = r1;
		if (ra[r1] == ra[r2])ra[r1]++;
	}
}
int n, m;
int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++) {
		init();
		scanf("%d%d", &n, &m);
		int x, y;
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			unite(x, y+n);
			unite(x + n, y);
			if (find(x) == find(x+n) || find(y)==find(y+n)) cnt = 1;
		}
		printf("Scenario #%d:\n", k);
		if (cnt)printf("Suspicious bugs found!\n\n");
		else printf("No suspicious bugs found!\n\n");
	}


	return 0;
}