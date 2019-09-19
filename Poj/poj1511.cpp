#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<vector>
#include<functional>
using namespace std;

typedef long long LL;
struct edge{
	int to, cost;
	edge() {}
	edge(int x, int y) {
		to = x;
		cost = y;
	}
};
const int maxn = 1000000 + 100;
const int INF = 0x7fffffff;
int n, m;
LL a[maxn][3];
typedef pair<int, int> P;
vector<edge> G[maxn];
LL d[maxn];
bool vis[maxn];

LL dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>> q;
	for (int i = 0; i <= n; i++) {
		d[i] = INF;
		vis[i] = 0;
	}
	d[1] = 0;
	q.push(P(0, 1));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int u = p.second;
		if (vis[u])continue;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			edge e = G[u][i];
			if (d[e.to] > d[u] + e.cost) {
				d[e.to] = d[u] + e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
	LL ans = 0;
	for (int i = 2; i <= n; i++) ans += d[i];
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < maxn; i++)G[i].clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++){
			scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
			G[a[i][0]].push_back(edge(a[i][1], a[i][2]));
		}
		LL ans = 0;
		ans += dijkstra(1);
		for (int i = 0; i < maxn; i++)G[i].clear();
		for (int i = 1; i <= m; i++) {
			G[a[i][1]].push_back(edge(a[i][0], a[i][2]));
		}
		ans += dijkstra(1);
		printf("%lld\n", ans);
	}
	return 0;
}