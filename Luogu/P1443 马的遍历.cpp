#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n, m, y, x;
int G[500][500];
int d[8][2] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };
struct node{
	int x, y, step;
	node() {}
	node(int _x,int _y,int _step):x(_x),y(_y),step(_step){}
};
void bfs(int x, int y) {
	queue<node> q;
	q.push(node(x, y, 0));
	G[x][y] = 0;
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int tx = t.x + d[i][0];
			int ty = t.y + d[i][1];
			if (ty >= 1 && ty <= m&&tx >= 1 && tx <= n&&G[tx][ty] == -1) {
				G[tx][ty] = t.step + 1;
				q.push(node(tx, ty, t.step + 1));
			}
		}
	}
}
int main() {
	memset(G, -1, sizeof(G));
	scanf("%d%d%d%d", &n, &m, &x, &y);
	bfs(x, y);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			printf("%-5d", G[i][j]);
		}
		printf("\n");
	}


	return 0;
}