#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

#define maxn 100100
bool vis[maxn];
int step[maxn];

int bfs(int n, int k) {
	queue<int> q;
	step[n] = 0;
	vis[n] = true;
	q.push(n);
	int head ;
	int next;
	while (!q.empty()) {
		head = q.front();
		q.pop();
		for (int i = 1; i <= 3; i++) {
			if (i == 1) next = head - 1;
			if (i == 2) next = head + 1;
			if (i == 3) next = head * 2;
			if (next<0 || next>100000) continue;
			if (!vis[next]) {
				vis[next] = true;
				q.push(next);
				step[next] = step[head] + 1;
			}
			if (next == k) return step[next];
		}
	}
}
int main() {
	int n, k;
	while (~scanf("%d%d", &n, &k)) {
		memset(vis, false, sizeof(vis));
		memset(step, 0, sizeof(step));
		if (n >= k)printf("%d\n", n - k);
		else printf("%d\n", bfs(n, k));
	}
	return 0;
}