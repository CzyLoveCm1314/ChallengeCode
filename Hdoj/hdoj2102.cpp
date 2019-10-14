#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 20;
char G[maxn][maxn][2];
const int inf = 0x3f3f3f3f;
struct node {
	int x, y, z, step;
	node(){}
	node(int _x,int _y,int _z,int _step):x(_x),y(_y),z(_z),step(_step){}
}s,p;
int n, m, T;
int dic[4][2] = { {1,0},{-1,0},{0,1},{0,-1}};
bool vis[maxn][maxn][2];


void print() {
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d", vis[i][j][k]);
			}
			printf("\n");
		}
		
	}
	printf("\n");
}

int bfs() {
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	while (!q.empty()) q.pop();
	q.push(s);
	vis[s.x][s.y][s.z] = true;
	while (!q.empty()) {
		node t = q.front();
		if (G[t.x][t.y][t.z]=='P') return t.step;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = t.x + dic[i][0];
			int yy = t.y + dic[i][1];
			int zz = t.z;
			if (xx >= 0 && xx < n&&yy >= 0 && yy < m&& !vis[xx][yy][zz]) {
				vis[xx][yy][zz] = true;
				if (G[xx][yy][zz] == '.'|| G[xx][yy][zz] == 'P') {
					q.push(node(xx, yy, zz, t.step + 1));
				}
				else if (G[xx][yy][zz] == '#'&&G[xx][yy][1-zz]!='*'&&G[xx][yy][1-zz]!='#') {
					q.push(node(xx, yy, 1-zz, t.step + 1));
				}
			}
		}
	}
	return inf;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &T);
		char op[20];
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < n; i++) {
				scanf("%s", op);
				for (int j = 0; j < m; j++) {
					G[i][j][k] = op[j];
					if (G[i][j][k] == 'P') p = node(i, j, k, 0);
				}
			}
			getchar();
		}
		s = node(0, 0, 0, 0);
		int cnt = bfs();
		//cout << cnt << endl;
		if (cnt <= T) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}