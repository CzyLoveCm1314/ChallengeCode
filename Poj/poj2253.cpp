#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn = 300;
int n;
int x[maxn], y[maxn];
double map[maxn][maxn];


void floyd(){
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));
}

int main() {
	int cnt = 1;
	while (scanf("%d", &n)!=EOF && n) {
		memset(map, 0,sizeof(map));
		for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++)
				map[i][j] = map[j][i] = sqrt(double(x[i] - x[j])*(x[i] - x[j]) + double(y[i] - y[j])*(y[i] - y[j]));
		}
		floyd();
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", cnt++, map[1][2]);
	}
	return 0;
}