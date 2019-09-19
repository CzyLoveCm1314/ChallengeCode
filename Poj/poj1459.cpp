#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int maxn = 120;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn];
bool vis[maxn];
int pre[maxn];
int n, np, nc, m;
char ch;

bool bfs() {
	queue<int> q;
	memset(pre, 0, sizeof(pre));
	memset(vis, false, sizeof(vis));
	vis[n+1] = true;
	q.push(n+1);
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		if (first == n) return true;
		for (int i = 0; i <= n+1; i++) {
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
		if (!bfs()) return ans;
		int MIN = inf;
		for (int i = n; i != n+1; i = pre[i])MIN = min(MIN, mp[pre[i]][i]);
		for (int i = n; i != n+1; i = pre[i]) {
			mp[pre[i]][i] -= MIN;
			mp[i][pre[i]] += MIN;
		}
		ans += MIN;
	}
	return ans;
}

int main() {
	while (~scanf("%d%d%d%d", &n, &np, &nc, &m)) {
		memset(mp, 0, sizeof(mp));
		int c, u, v;
		for (int i = 1; i <= m; i++) {
			cin >> ch >> u >> ch >> v >> ch >> c;
			mp[u][v] += c;
		}
		for (int i = 1; i <= np; i++) {
			cin >> ch >> u >> ch >> c;
			mp[n + 1][u] = c;	//n+1是源点
		}
		for (int i = 1; i <= nc; i++) {
			cin >> ch >> u >> ch >> c;
			mp[u][n] = c;		//n是汇点
		}
		printf("%d\n", maxflow());
	}
	return 0;
}

