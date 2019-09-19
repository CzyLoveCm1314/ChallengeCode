#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct edge {
	int f, t, c;
}e[5200];
int cnt;
int dis[3000];
bool bellman(int n) {
	for (int i = 0; i < 3000; i++)dis[i] = 0x3f3f3f3f;
	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < cnt; j++) {
			if (dis[e[j].t]>dis[e[j].f] + e[j].c) {
				dis[e[j].t] = dis[e[j].f] + e[j].c;
			}
		}
	}
	for (int j = 0; j<cnt; j++)
		if (dis[e[j].t]>dis[e[j].f] + e[j].c)
			return true;
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		memset(e, 0, sizeof(e));
		int n, m, w;
		scanf("%d%d%d",&n, &m, &w);
		for (int i = 1; i <= m; i++) {
			int f, t, c;
			scanf("%d%d%d", &f, &t, &c);
			e[cnt].f = f;
			e[cnt].t = t;
			e[cnt++].c = c;
			e[cnt].f = t;
			e[cnt].t = f;
			e[cnt++].c = c;
		}
		for (int i = 1; i <= w; i++) {
			int f, t, c;
			scanf("%d%d%d", &f, &t, &c);
			e[cnt].f = f;
			e[cnt].t = t;
			e[cnt++].c = -c;
		}
		if (bellman(n))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}