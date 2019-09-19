#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 53000;

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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < maxn; i++) E[i].clear();
	int s = INF, t = -INF;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		s = min(s, a);
		t = max(t, b + 1);
		E[b + 1].push_back(Edge(a, -c));
	}
	for (int i = s; i < t; i++) {
		E[i + 1].push_back(Edge(i, 0));
		E[i].push_back(Edge(i + 1 , 1));
	}
	SPFA(t, maxn);
	printf("%d\n", -dist[s]);
	
	return 0;
}