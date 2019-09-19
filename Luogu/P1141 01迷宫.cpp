#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int maxn = 1100;
int G[maxn][maxn], vis[maxn][maxn];
int num[maxn*maxn];
string str;
int n, m;
int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void dfs(int x, int y, int flag, int step) {
	vis[x][y] = step;
	int tx, ty;
	for (int i = 0; i < 4; i++) {
		tx = x + d[i][0];
		ty = y + d[i][1];
		if (tx <= n&&tx >= 1 && ty <= n&&ty >= 1 && !vis[tx][ty]) {
			if (flag==0 && G[tx][ty] == 1)dfs(tx, ty, 1, step);
			else if (flag==1 && G[tx][ty] == 0) dfs(tx, ty, 0, step);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			G[i][j+1] = str[j] - '0';
	}
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[i][j])dfs(i, j, G[i][j], cnt++);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			num[vis[i][j]]++;
		}
	}
	int x, y;
	while (m--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", num[vis[x][y]]);
	}
	return 0;
}