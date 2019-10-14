//https://www.cnblogs.com/DOLFAMINGO/p/7538576.html
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 100 + 10;
int m, n, k, d;
bool G[maxn][maxn];
bool hav[maxn][maxn][1010];
bool vis[maxn][maxn][1010];
struct bullet {
	int dir, t, v, x, y;
}bu[maxn];
struct node {
	int x, y, step;
	node() {}
	node(int _x,int _y,int _step):x(_x),y(_y),step(_step){}
};
int moves[5][2] = { {-1,0}, {1,0}, {0,1},{ 0,-1},{0 ,0} };

void init() {
	memset(hav, 0, sizeof(hav));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= d; j += bu[i].t) {
			for (int k = 1;; k++) {
				int x = bu[i].x + moves[bu[i].dir][0] * k;
				int y = bu[i].y + moves[bu[i].dir][1] * k;
				if (x<0 || x>n || y<0 || y>m || G[x][y]) break;
				if (k % bu[i].v == 0) hav[x][y][j + k / bu[i].v] = true;
			}
		}
	}
}
int bfs() {
	queue<node> q;
	memset(vis, 0, sizeof(vis));
	while (!q.empty())q.pop();
	node now, tmp;
	now.x = now.y = now.step = 0;
	vis[0][0][0] = true;
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.step > d) return -1;
		if (now.x == n&& now.y == m) return now.step;

		for (int i = 0; i < 5; i++) {
			tmp.x = now.x + moves[i][0];
			tmp.y = now.y + moves[i][1];
			tmp.step = now.step + 1;
			if (tmp.x >= 0 && tmp.x <= n && tmp.y >= 0 && tmp.y <= m && !G[tmp.x][tmp.y]
				&& !hav[tmp.x][tmp.y][tmp.step] && !vis[tmp.x][tmp.y][tmp.step]){
				vis[tmp.x][tmp.y][tmp.step] = true;
				q.push(tmp);
			}
		}
	}
	return -1;
}
int main() {
	while (~scanf("%d%d%d%d", &n, &m, &k, &d)) {
		memset(G, false, sizeof(G));
		char dir;
		for (int i = 0; i < k; i++) {
			getchar();
			scanf("%c%d%d%d%d", &dir, &bu[i].t, &bu[i].v, &bu[i].x, &bu[i].y);
			if (dir == 'N') bu[i].dir = 0;
			if (dir == 'S') bu[i].dir = 1;
			if (dir == 'E') bu[i].dir = 2;
			if (dir == 'W') bu[i].dir = 3;
			G[bu[i].x][bu[i].y] = 1;
		}
		init();
		int ans = bfs();
		if (ans == -1) puts("Bad luck!");
		else printf("%d\n", ans);
	}
	return 0;
}