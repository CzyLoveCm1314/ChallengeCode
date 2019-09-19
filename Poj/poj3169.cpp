#include<iostream>
#include<cstdio>
#include<functional>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 1100;
const int INF = 0x3f3f3f3f;
struct Edge {
	int v;
	int cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
bool vis[maxn];
int dis[maxn];
int cnt[maxn];
int n, ml, md;

bool spfa(int s, int n) {
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
		dis[i] = INF;
		cnt[i] = 0;
	}
	vis[s] = true;
	dis[s] = 0;
	queue<int> q;
	while (!q.empty())q.pop();
	q.push(s);
	cnt[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 0; i < E[u].size(); i++) {
			int v = E[u][i].v;
			if (dis[v] > dis[u] + E[u][i].cost) {
				dis[v] = dis[u] + E[u][i].cost;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
					if (++cnt[v] > n) return false;
				}
			}
		}
	}
	return true;
}
int main() {
	while (~scanf("%d%d%d", &n, &ml, &md)) {
		for (int i = 0; i <= n; i++) E[i].clear();
		int a, b, c;
		for (int i = 1; i <= ml; i++) {
			scanf("%d%d%d", &a, &b, &c);
			E[a].push_back(Edge(b, c));
		}
		for (int i = 1; i <= md; i++) {
			scanf("%d%d%d", &a, &b, &c);
			E[b].push_back(Edge(a, -c));
		}
		int flag = spfa(1, n);
		if(!flag) printf("-1\n");
		else if(dis[n] == INF)printf("-2\n");
		else printf("%d\n", dis[n]);
	}
	return 0;
}