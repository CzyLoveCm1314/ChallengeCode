#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn = 1000;
const int INF = 0x3f3f3f3f;
int c;
double G[maxn][maxn];

struct node {
	double x, y;
	node(){}
	node(double _x,double _y):x(_x),y(_y){}
}a[maxn];

double prim(int n) {
	double sum = 0;
	double lowcost[maxn];
	bool vis[maxn];
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; i++)lowcost[i] = G[0][i];
	vis[0] = true;
	lowcost[0] = 0;
	int k = 0;
	for (int i = 0; i < n - 1; i++) {
		double min = INF;
		for (int j = 0; j < n; j++) {
			if (min > lowcost[j]&& !vis[j]) {
				min = lowcost[j];
				k = j;
			}
		}
		if (min == INF) return 0;
		vis[k] = true;
		sum += lowcost[k];
		for (int j = 0; j < n; j++) {
			if (G[k][j] < lowcost[j] && !vis[j]) lowcost[j] = G[k][j];
		}
	}
	return sum;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(G, 0x3f, sizeof(G));
		scanf("%d", &c);
		for (int i = 0; i < c; i++)scanf("%lf%lf", &a[i].x, &a[i].y);
		for (int i = 0; i < c; i++)
			for (int j = 0; j < c; j++) {
				double dis = sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y));
				//cout << i << ' ' << j << ' ' << dis <<endl;
				if (dis < 10.000000 || dis>1000.000000) dis = INF;
				G[i][j] = dis;
			}
		double sum = prim(c);
		//cout << sum << endl;
		if (sum==0) printf("Oh!\n");
		else printf("%.1lf\n", prim(c)*100);
	}
	return 0;
}