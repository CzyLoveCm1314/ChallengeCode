#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int n, m;
const int maxn = 1000;
char A[maxn][maxn];
bool mark[maxn][maxn][2], flag, uesd[maxn][maxn];
struct node{
	int x, y, step, leave;
}M, G, Z[2];


bool check(int x, int y, int num, int step){
	if (x<0 || x >= n || y<0 || y >= m || mark[x][y][num] || A[x][y] == 'X' || 
		abs(x - Z[0].x) + abs(y - Z[0].y) <= 2 * step || abs(x - Z[1].x) + abs(y - Z[1].y) <= 2 * step)
		return 0;
	return 1;
}
bool check(int x, int y, int step){
	if (abs(x - Z[0].x) + abs(y - Z[0].y) <= 2 * step || abs(x - Z[1].x) + abs(y - Z[1].y) <= 2 * step)
		return 0;
	return 1;
}

int bfs() {

}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(mark, 0, sizeof(mark));
		int k = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", A[i]);
			for (int j = 0; i < m; j++) {
				if (A[i][j] == 'M'){
					M.x = i;
					M.y = j;
					M.leave = 0;
					mark[i][j][0] = 1;
					M.step = 0;
				}
				else if (A[i][j] == 'G'){
					G.x = i;
					G.y = j;
					G.leave = 0;
					mark[i][j][1] = 1;
					G.step = 0;
				}
				else if (A[i][j] == 'Z'){
					Z[k].x = i;
					Z[k].y = j;
					Z[k++].step = 0;
				}
			}
		}
		printf("%d\n", bfs());
	}
	return 0;
}