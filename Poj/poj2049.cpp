#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int  maxn = 250;
const int inf = 0x3f3f3f3f;
struct node {
	int x, y, d;
	bool operator<(const node &a)const{
		return a.d<d;
	}

};
int dis[maxn][maxn];
int h[maxn][maxn], l[maxn][maxn];
int n, m, maxx, maxy, sx, sy;

void bfs() {
	priority_queue <node> q;
	for (int i = 0; i <= maxx; i++) {
		for (int j = 0; j <= maxy; j++) dis[i][j] = inf;
	}
	node k;
	k.x = 0;
	k.y = 0; 
	k.d = 0;
	dis[0][0] = 0;
	q.push(k); 
	while (!q.empty()) {
		k = q.top();
		q.pop();
		if (k.x == sx&&k.y == sy) return;
		int x = k.x;
		int y = k.y;
		if (y + 1 <= maxy&&dis[x][y + 1]>dis[x][y] + h[x][y + 1]){
			dis[x][y + 1] = dis[x][y] + h[x][y + 1];
			k.x = x;
			k.y = y + 1;
			k.d = dis[x][y + 1];
			q.push(k);
		}
		if (y - 1 >= 0 && dis[x][y - 1]>dis[x][y] + h[x][y]){
			dis[x][y - 1] = dis[x][y] + h[x][y];
			k.x = x;
			k.y = y - 1;
			k.d = dis[x][y - 1];
			q.push(k);
		}
		if (x + 1 <= maxx&&dis[x + 1][y]>dis[x][y] + l[x + 1][y]){
			dis[x + 1][y] = dis[x][y] + l[x + 1][y];
			k.x = x + 1;
			k.y = y;
			k.d = dis[x + 1][y];
			q.push(k);
		}
		if (x - 1 >= 0 && dis[x - 1][y]>dis[x][y] + l[x][y]){
			dis[x - 1][y] = dis[x][y] + l[x][y];
			k.x = x - 1;
			k.y = y;
			k.d = dis[x - 1][y];
			q.push(k);
		}
	}
	dis[sx][sy] = -1;
}

int main() {
	int x, y, d, t;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (m == -1 && n == -1)break;
		memset(h, 0, sizeof(h));
		memset(l, 0, sizeof(l));
		maxy = -1; 
		maxx = -1;
		while (n--)
		{
			scanf("%d%d%d%d", &x, &y, &d, &t);
			if (d){
				for (int i = 0; i<t; ++i) l[x][y + i] = inf;
				maxx = max(maxx, x);
				maxy = max(maxy, y + t);
			}
			else{
				for (int i = 0; i < t; ++i)h[x + i][y] = inf;
				maxx = max(maxx, x + t);
				maxy = max(maxy, y);
			}
		}
		while (m--){
			scanf("%d%d%d", &x, &y, &d);
			if (d) l[x][y] = 1;
			else h[x][y] = 1;
		}
		double f1, f2;
		scanf("%lf%lf", &f1, &f2);
		if (f1 >= maxx || f2 >= maxy) {
			printf("0\n");
			continue;
		}
		sx = f1;
		sy = f2;
		bfs();
		printf("%d\n", dis[sx][sy]);
	}
	return 0;
}