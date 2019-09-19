#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 120;
int a[maxn][maxn];//��¼A����S��λ��
int map[maxn][maxn];//����ͼ
int dis[maxn][maxn];//��¼��͵�֮��ľ���
bool vis[maxn];//���Ƿ񱻷��ʹ�
int t[maxn][maxn];//bfs��¼����
int mincost[maxn];//prim�����ж��㼯����С����
int mov[][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };//��������

void bfs(int sx, int sy){
	queue<pair<int, int> >q;
	while (!q.empty()) q.pop();
	memset(t, -1, sizeof(t));
	t[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		if (a[now.first][now.second] != -1)
			dis[a[sx][sy]][a[now.first][now.second]] = t[now.first][now.second];
		for (int i = 0; i<4; i++){
			int tx = now.first + mov[i][0];
			int ty = now.second + mov[i][1];
			if (map[tx][ty] == '#' || t[tx][ty] != -1)continue;
			t[tx][ty] = t[now.first][now.second] + 1;
			q.push(make_pair(tx, ty));
		}
	}
}
int prim(int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		vis[i] = false;
		mincost[i] = dis[0][i];
	}
	vis[0] = true;
	mincost[0] = 0;
	while (true) {
		int v = -1;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && (v == -1 || mincost[i] < mincost[v])) v = i;
		}
		if (v == -1)break;
		ans += mincost[v];
		vis[v] = true;
		for (int i = 0; i < n; i++) {
			mincost[i] = min(mincost[i], dis[v][i]);
		}
	}
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int col, row;
		int cnt = 0;
		char op[maxn];
		memset(a, -1, sizeof(a));
		memset(dis, 0x3f, sizeof(dis));
		scanf("%d%d", &col, &row);
		gets_s(op);
		for (int i = 0; i < row; i++) {
			gets_s(op);
			for (int j = 0; j < col; j++) {
				map[i][j] = op[j];
				if (map[i][j] == 'A' || map[i][j] == 'S') {
					a[i][j] = cnt++;
				}
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (a[i][j] != -1)
					bfs(i, j);
			}
		}
		printf("%d\n", prim(cnt));
	}
	return 0;
}