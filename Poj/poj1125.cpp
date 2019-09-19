#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
int map[maxn][maxn];

int main() {
	int n;
	while (scanf("%d", &n) != EOF&&n) {
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++) map[i][j] = INF;
		for (int i = 1; i <= n; i++) {
			int cnt;
			scanf("%d", &cnt);
			int t, c;
			for (int j = 1; j <= cnt; j++) {
				scanf("%d%d", &t, &c); 
				map[i][t] = c;
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
		int minx = INF;
		int person = 1;
		for (int i = 1; i <= n; i++) {
			int temp = 0;
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (map[i][j] > temp)temp = map[i][j];
			}
			if (temp < minx) {
				minx = temp;
				person = i;
			}
		}
		printf("%d %d\n", person, minx);
	}
	return 0;
}
