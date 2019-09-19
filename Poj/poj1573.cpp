#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define maxn 12
char map[maxn][maxn];
bool  vis[maxn][maxn];
int step[maxn][maxn];
int a, b, m,temp;

void dfs(int x, int y,int t) {
	temp++;
	if(x<1||x>a||y<1||y>b) {
		printf("%d step(s) to exit\n", temp-1);
		return;
	}
	if (vis[x][y]){
		printf("%d step(s) before a loop of %d step(s)\n", step[x][y]-1, temp - step[x][y]);
		return;
	}
	vis[x][y] = true;
	step[x][y] = temp;
	int xx, yy;
	if (map[x][y] == 'S'){
		xx = x + 1;
		yy = y;
	}
	else if (map[x][y] == 'N'){
		xx = x - 1;
		yy = y;
	}
	else if (map[x][y] == 'W'){
		xx = x;
		yy = y - 1;
	}
	else if (map[x][y] == 'E'){
		xx = x;
		yy = y + 1;
	}
	dfs(xx, yy, temp + 1);
}

int main() {
	char str[maxn];
	while (scanf("%d%d%d", &a, &b, &m) != EOF &&a&&b&&m) {
		for (int i = 1; i <= a; i++) {
			scanf("%s", str);
			for (int j = 1; j <= b; j++) {
				map[i][j] = str[j - 1];
			}
		}
		memset(vis, 0, sizeof(vis));
		temp = 0;
		dfs(1, m, 0);
	}
	return 0;
}