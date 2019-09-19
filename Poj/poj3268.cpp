#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

#define maxn 1010
const int inf = 0x3f3f3f3f;
int n, m, x;

struct edge {
	int to, cost;
	edge() {}
	edge(int x, int y) {
		to = x;
		cost = y;
	}
};
typedef pair<int, int> P;
vector<edge> G[maxn];
int d[maxn];
bool vis[maxn];

int dijskra(int s, int e) {
	priority_queue<P,vector<P>,greater<P>> q;
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	q.push(P(0, s)); //P是pair<int,int> 第一位存距离，第二位存下标
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		if (p.second == e) return d[e];
		if (d[p.second]< p.first) continue;
		int v = p.second;
		for (int i = 0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to]>d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &x);
	int a, b, c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back(edge(b, c));
	}
	int sum = -1;
	for (int i = 1; i <= n; i++) {
		sum = max(dijskra(i, x) + dijskra(x, i), sum);;
	}
	printf("%d\n", sum);
	return 0;
}