#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<functional>
using namespace std;

const int maxn = 31000;
int n,m;
struct edge {
	int to, cost;
	edge(){}
	edge(int a,int b):to(a),cost(b){}
};
struct Edge{
	int v, cost;
	int next;
};
Edge edge[200000];
int tol;
int head[maxn];
typedef pair<int, int> P;
int d[maxn];
bool vis[maxn];

int dijkstra(int s, int e) {
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
		d[i] = 0x3f3f3f3f;
	}
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	while (!q.empty())q.pop();
	q.push(P(0,s));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int u = p.second;
		if (vis[u])continue;
		vis[u] = true;
		for (int i = head[u]; i !=-1; i = edge[i].next) {
			Edge e = edge[i];
			if (!vis[e.v]&&d[e.v] > d[u] + e.cost) {
				d[e.v] = d[u] + e.cost;
				q.push(P(d[e.v], e.v));
			}
		}
	}
	return d[e];
}
int main() {
	while (~scanf("%d%d", &n, &m)) {
		tol = 0;
		memset(head, -1, sizeof(head));
		int a, b, c;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge[tol].v = b;
			edge[tol].cost = c;
			edge[tol].next = head[a];
			head[a] = tol++;
		}
		printf("%d\n", dijkstra(1, n));
	}
	return 0;
}