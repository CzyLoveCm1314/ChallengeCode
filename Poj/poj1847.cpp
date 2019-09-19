#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

#define maxn 110
struct edge {
	int to, cost;
	edge(){}
	edge(int a,int b):to(a),cost(b){}
};
vector<edge> vc;
const int INF = 0x3f3f3f3f;
int n, a, b;
int G[maxn][maxn];
typedef pair<int, int> P;
int d[maxn];
int vis[maxn];
int dijkstra(int s, int e) {
	priority_queue<P, vector<P>, greater<P>> q;
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[s] = 0;
	q.push(P(0, s));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (v == e) return d[e];
		if (vis[v]) continue;
		vis[v] = true;
		for (int i = 1; i<= n; i++) {
			if (!vis[i]&& d[i]>d[v] + G[v][i]) {
				d[i] = d[v] + G[v][i];
				q.push(P(d[i], i));
			}
		}
	}
	return d[e];
}
int main() {
	while (scanf("%d%d%d", &n, &a, &b) != EOF) {
		int t;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) 
				G[i][j] = INF;
		}
		int m;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &m);
			for (int j = 1; j <= m; j++) {
				scanf("%d", &t);
				if (j == 1)G[i][t] = 0;
				else G[i][t] = 1;
			}
		}
		int cnt = dijkstra(a, b);
		if(cnt!=INF)printf("%d\n", cnt);
		else printf("-1\n");
	}
	return 0;
}