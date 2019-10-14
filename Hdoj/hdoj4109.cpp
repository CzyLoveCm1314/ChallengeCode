#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 2000;
const int INF = 0x3f3f3f3f;
int n, m;
struct Edge {
	int v;
	int cost;
	Edge(int _v = 0, int _cost = 0) :v(_v), cost(_cost) {}
};
vector<Edge>E[maxn];
bool vis[maxn];
int cnt[maxn];
int dist[maxn];

bool SPFA(int start, int n) {
	memset(vis, false, sizeof(vis));
	for (int i = 0; i <= n; i++) dist[i] = INF;
	vis[start] = true;
	dist[start] = 0;
	queue<int>que;
	while (!que.empty())que.pop();
	que.push(start);
	memset(cnt, 0, sizeof(cnt));
	cnt[start] = 1;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = 0; i<E[u].size(); i++) {
			int v = E[u][i].v;
			if (dist[v]>dist[u] + E[u][i].cost) {
				dist[v] = dist[u] + E[u][i].cost;
				if (!vis[v]) {
					vis[v] = true;
					que.push(v);
					if (++cnt[v]>n) return false;
				}
			}
		}
	}
	return true;
}
int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++) E[i].clear();
		int u, v, w;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			E[v].push_back(Edge(u, -w));
		}
		for (int i = 0; i < n; i++) {
			E[n].push_back(Edge(i, 0));
			E[i].push_back(Edge(n + 1, -1));
		}
		SPFA( n, n+1);
		printf("%d\n", -dist[n+1]);
	}
	return 0;
}