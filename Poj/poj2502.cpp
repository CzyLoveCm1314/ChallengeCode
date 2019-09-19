#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 300;
struct Node {
	double x, y;
}node[maxn];
double a[maxn][maxn];
double d[maxn];
bool vis[maxn];

double dis(Node a, Node b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double dijkstra(int s, int n) {
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
		d[i] = a[1][i];
	}
	d[s] = 0;
	vis[s] = true;
	for (int i = 1; i<n; i++){
		int k = -1;
		for (int j = 1; j<=n; j++)
			if (!vis[j] && (k == -1 || d[k]>d[j]))k = j;
		if (k == -1)break;
		vis[k] = true;
		for (int j = 1; j<= n; j++)
			if (!vis[j] && d[j]> d[k] + a[k][j])
				d[j] = d[k] + a[k][j];
	}

	return d[2];
}
int main() {
	double v1 = 10000.0 / 60;
	double v2 = 40000.0 / 60;
	while (scanf("%lf%lf%lf%lf", &node[1].x, &node[1].y, &node[2].x, &node[2].y) == 4) {
		for (int i = 0; i<300; i++)
			for (int j = 0; j<300; j++) {
				if (i == j) a[i][j] = 0;
				else a[i][j] = 1e30;
			}
		int n = 2;
		int cnt1 = 3;
		int xx, yy;
		while (scanf("%d%d", &xx, &yy) == 2) {
			if (xx == -1 && yy == -1) {
				cnt1 = n + 1;
				continue;
			}
			n++;
			node[n].x = xx;
			node[n].y = yy;
			if (n != cnt1) a[n][n - 1] = a[n - 1][n] = min(a[n][n - 1], dis(node[n], node[n - 1]) / v2);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = min(a[i][j], dis(node[i], node[j]) / v1);
		printf("%.0lf\n", dijkstra(1, n));
	}
	return 0;
}