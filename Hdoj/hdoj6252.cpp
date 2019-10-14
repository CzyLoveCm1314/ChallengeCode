#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2010;
struct Edge {
	int v, cost;
	Edge(int _v,int _cost):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
bool vis[maxn];
int cnt[maxn];
int dis[maxn];
int n, m, x;

bool SPFA(int start, int n) {
	memset(vis, false, sizeof(vis));
	for (int i = 0; i <= n; i++) dis[i] = INF;
	vis[start] = true;
	dis[start] = 0;
	queue<int> que;
	que.push(start);
	memset(cnt, 0, sizeof(cnt));
	cnt[start] = 1;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = 0; i < E[u].size(); i++) {
			int v = E[u][i].v;
			if (dis[v] > dis[u] + E[u][i].cost) {
				dis[v] = dis[u] + E[u][i].cost;
				if (!vis[v]) {
					vis[v] = true;
					que.push(v);
					if (++cnt[v] > n) return false;
				}
			}
		}
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++) {
		scanf("%d%d%d", &n, &m, &x);
		for (int i = 0; i <= n; i++) E[i].clear();
		int a, b, c, d;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (a == b) {
				if (c == d) {
					//a==b,c==d,b!=c
					E[a].push_back(Edge(c, x));
					E[d].push_back(Edge(a, -x));
				}
				else {
					if (b == c) {
						//a==b==c,c!=d		
						//d-a>x		d-a>=x+1 a-d<=-x-1
						E[d].push_back(Edge(a, -x - 1));
					}
					else {
						//a==b,b!=c,c!=d
						//d-a>x		d-a>=x+1 a-d<=-x-1
						//c-b<x		c-b<=x-1
						E[d].push_back(Edge(a, -x - 1));
						E[b].push_back(Edge(c, x - 1));
					}
				}
			}
			else {
				if (c == d) {
					if (b == c) {
						//a!=b,b==c==d 
						//d-a>x		d-a>=x+1 a-d<=-x-1
						E[d].push_back(Edge(a, -x - 1));
					}
					else {
						//a!=b,b!=c,c==d
						//d-a>x		d-a>=x+1 a-d<=-x-1
						E[d].push_back(Edge(a, -x - 1));
						//c-b<x		c-b<=x-1
						E[b].push_back(Edge(c, x - 1));
					}
				}
				else {
					if (b == c) {
						//a!=b,b==c,c!=d
						//d-a>x		d-a>=x+1 a-d<=-x-1
						E[d].push_back(Edge(a, -x - 1));
					}
					else {
						//a!=b,b!=c,c!=d
						//d-a>x		d-a>=x+1 a-d<=-x-1
						E[d].push_back(Edge(a, -x - 1));
						//c-b<x		c-b<=x-1
						E[b].push_back(Edge(c, x - 1));
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			//a2>a1		a2-a1>=1,a1-a2<=-1
			if (i > 1) E[i].push_back(Edge(i - 1, -1));
			E[0].push_back(Edge(i, 0));
		}
		if (SPFA(0, n)) {
			printf("Case #%d:", z);
			for (int i = 1; i <= n - 1; i++) printf(" %d", dis[i + 1] - dis[i]);
			printf("\n");
		}
		else printf("Case #%d: IMPOSSIBLE\n", z);
	}
	return 0;
}