#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int G[50][50];
int a[50][50];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void dfs(int x, int y) {
	int tx, ty;
	for (int i = 0; i < 4; i++) {
		tx = x + d[i][0];
		ty = y + d[i][1];
		if (tx <= n+1&&tx >= 0 && ty <= n+1&&ty >= 0 && G[tx][ty] != 1) {
			G[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &G[i][j]);
			a[i][j] = G[i][j];
		}
	dfs(0, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (G[i][j] == 0) G[i][j] = 2;
	for (int i = 1; i <= n; i++) {
		if (G[i][1] != 2) printf("%d", a[i][1]);
		else printf("2");
		for (int j = 2; j <= n; j++) {
			if(G[i][j] != 2) printf(" %d", a[i][j]);
			else printf(" 2");
		}
		printf("\n");
	}
	return 0;
}