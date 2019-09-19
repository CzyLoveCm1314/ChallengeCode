#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1010;
int s;
struct Node {
	double x, y;
	Node(){}
	Node(double _x, double _y) :x(_x), y(_y) {}
}a[maxn];
double G[maxn][maxn];

double distance(double x1,double y1,double x2,double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
double prim(int n) {
	double lowcost[maxn];
	bool vis[maxn];
	double dis[maxn];
	int cnt = 0;
	memset(lowcost, 0x3f, sizeof(lowcost));
	memset(vis, false, sizeof(vis));
	for (int j = 0; j < n; j++) lowcost[j] = G[0][j];
	int k = 0;
	vis[0] = true;
	for (int i = 1; i <= n - 1; i++) {
		int min = INF;
		for (int j = 0; j < n; j++) {
			if (min> lowcost[j])
				if (!vis[j]) {
					k = j;
					min = lowcost[j];
				}
		}
		vis[k] = true;
		dis[cnt++] = lowcost[k];
		for (int j = 0; j < n; j++)
			if (G[k][j] < lowcost[j] && !vis[j]) lowcost[j] = G[k][j];
	}
	sort(dis, dis + cnt);
	return dis[n - 2- ( s - 1)];
}
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		memset(G, 0x3f, sizeof(G));
		scanf("%d%d", &s, &n);
		for (int i = 0; i < n; i++)scanf("%lf%lf", &a[i].x, &a[i].y);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				G[i][j] = distance(a[i].x, a[i].y,a[j].x,a[j].y);
		printf("%.2lf\n", prim(n));
	}
	return 0;
}