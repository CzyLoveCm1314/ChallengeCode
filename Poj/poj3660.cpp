#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 110;
int a[maxn][maxn];
int n, m;

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(a, 0, sizeof(a));
		int x, y;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (a[i][k] && a[k][j])a[i][j] = 1;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int j;
			for (j = 1; j <= n; j++) {
				if (i == j)continue;
				if (a[i][j] == 0 && a[j][i] == 0)break;
			}
			if (j > n)ans++;
		}
		printf("%d\n", ans);

	}
	return 0;
}