#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 1000;
const int INF = 0x3f3f3f3f;
double G[maxn][maxn];

struct node {
	double x, y, z, r;
}a[maxn];
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));
}
double prim(int n) {
	double sum = 0;
	double lowcost[maxn];
	bool vis[maxn];
	for (int i = 0; i < n; i++) {
		lowcost[i] = G[0][i];
		vis[i] = false;
	}
	lowcost[0] = 0;
	vis[0] = true;
	int k = 0;
	for (int i = 1; i <= n - 1; i++) {
		double min = INF;
		for (int j = 0; j < n; j++) {
			if (lowcost[j] < min &&!vis[j]) {
				k = j;
				min = lowcost[j];
			}
		}
		if (min == INF)return -1;
		vis[k] = true;
		sum += lowcost[k];
		for (int i = 0; i < n; i++) {
			if (!vis[i] && lowcost[i]>G[k][i])
				lowcost[i] = G[k][i];
		}
	}
	return sum;
}
int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		memset(G, 0x3f, sizeof(G));
		for (int i = 0; i < n; i++)scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z, &a[i].r);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				double dis = distance(a[i].x, a[i].y, a[i].z, a[j].x, a[j].y, a[j].z);
				if (dis - a[i].r - a[j].r < 0) G[i][j] = 0;
				else G[i][j] = dis - a[i].r - a[j].r;
			}
		printf("%.3lf\n", prim(n));
	}
	return 0;
}