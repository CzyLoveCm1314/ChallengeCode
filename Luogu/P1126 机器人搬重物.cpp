#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n, m, sy, sx, ex, ey;
int G[500][500];
int vis[500][500];
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct node {
	int x, y, step;
	char dir;
	node() {}
	node(int _x, int _y, int _step,char _dir) :x(_x), y(_y), step(_step),dir(_dir) {}
};
int bfs(int x, int y ,char dir) {
	queue<node> q;
	q.push(node(x, y, 0, dir));
	vis[x][y] = 1;
	while (!q.empty()) {
		node u = q.front();
		if (u.x == ex&&u.y == ey) return u.step;
		for (int i = 0; i < 4; i++) {
			int tx = u.x + d[i][0];
			int ty = u.y + d[i][1];
		}
	}
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &G[i][j]);
	}
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	getchar();
	char dir;
	scanf("%c", &dir);
	printf("%d\n", bfs(sx, sy, dir));
	return 0;
}