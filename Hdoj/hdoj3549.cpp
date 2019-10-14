#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 20;
const int inf = 0x3f3f3f3f;
int pre[maxn];
bool vis[maxn];
int n, m;
int s, e;
int mp[maxn][maxn];

bool bfs() {
	queue<int> q;
	memset(pre, 0, sizeof(pre));
	memset(vis, false, sizeof(vis));
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		if (first == e) return true;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && mp[first][i]) {
				q.push(i);
				pre[i] = first;
				vis[i] = true;
			}
		}
	}
	return false;
}
int maxflow() {
	int ans = 0;
	while (1) {
		if (!bfs())return ans;
		int MIN = inf;
		for (int i = e; i != s; i = pre[i])MIN = min(MIN, mp[pre[i]][i]);
		for (int i = e; i != s; i = pre[i]){
			mp[pre[i]][i] -= MIN;
			mp[i][pre[i]] += MIN;
		}
		ans += MIN;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t;k++) {
		memset(mp, 0, sizeof(mp));
		scanf("%d%d", &n, &m);
		s = 1;
		e = n;
		int u, v, c;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &u, &v, &c);
			mp[u][v] += c;
		}
		printf("Case %d: %d\n", k, maxflow());
	}
	return 0;
}