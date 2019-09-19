#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 100;
const int inf = 0x3f3f3f3f;
int mp[maxn][maxn];
bool vis[maxn];
int pre[maxn];
int N;
int in[maxn][15];
int out[maxn][15];
int p, n;

bool bfs(int s,int e) {
	queue<int> q;
	memset(pre, 0, sizeof(pre));
	memset(vis, false, sizeof(vis));
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		if (first == e) return true;
		for (int i = 0; i < N; i++) {
			if (!vis[i] && mp[first][i]) {
				q.push(i);
				pre[i] = first;
				vis[i] = true;
			}
		}
	}
	return false;
}

int maxflow(int s,int e) {
	int ans = 0;
	while (1) {
		if (!bfs(s,e)) return ans;
		int MIN = inf;
		for (int i = e; i != s; i = pre[i])MIN = min(MIN, mp[pre[i]][i]);
		for (int i = e; i != s; i = pre[i]) {
			mp[pre[i]][i] -= MIN;
			mp[i][pre[i]] += MIN;
		}
		ans += MIN;
	}
	return ans;
}

int matchS(int *a){
	for (int i = 1; i <= p; i++)
		if (a[i] == 1) return 0;
	return 1;
}
int matchE(int *a){
	for (int i = 1; i <= p; i++)
		if (a[i] == 0) return 0;
	return 1;
}
int match(int *a, int *b){
	int flag = 1;
	for (int i = 1; i <= p; i++){
		if (a[i] == b[i]) continue;
		if (a[i] == 2) continue;
		if (b[i] == 2) continue;
		flag = 0;
		break;
	}
	return flag;
}
int main() {
	while (scanf("%d%d", &p, &n) != EOF) {
		memset(mp, 0, sizeof(mp));
		N = 2 * n + 2;
		for (int i = 1; i <= n; i++) {
			int c;
			scanf("%d", &c);
			mp[2 * i - 1][2 * i] += c;
			for (int j = 1; j <= p; j++)scanf("%d", &in[i][j]);
			for (int j = 1; j <= p; j++)scanf("%d", &out[i][j]);
		}
		int s = 0, e = N - 1;
		for (int i = 1; i <= n; i++){
			if (matchS(in[i])) mp[s][2 * i - 1] = inf;
			if (matchE(out[i])) mp[2 * i][e] = inf;
			for (int j = 1; j <= n; j++){
				if (j == i) continue;
				if (match(in[i], out[j])) mp[2 * j][2 * i - 1] = inf;
			}
		}
		printf("%d ", maxflow(s, e));
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				if (mp[2 * i][2 * j - 1] != 0 && mp[2 * i][2 * j - 1] != inf) ans++;
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				if (mp[2 * i][2 * j - 1] != 0 && mp[2 * i][2 * j - 1] != inf)
					printf("%d %d %d\n", i, j, inf - mp[2 * i][2 * j - 1]);
			}
		}
	}
	return 0;
}