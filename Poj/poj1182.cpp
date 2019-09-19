#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 50000 + 10;

int fa[maxn*3], a[maxn*3];
int ran[maxn*3];

void init() {
	int i;
	for (i = 1; i <= 3*maxn; i++){
		fa[i] = i;
		ran[i] = 0;
	}
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int a, int b) {
	int r1 = find(a);
	int r2 = find(b);
	if (r1 == 0) fa[r2] = r1;
	else if (r2 == 0) fa[r1] = r2;
	else fa[r1] = r2;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
		init();
		int d, x, y;
		int cnt = 0;
		for (int i = 1; i <= k; i++) {
			scanf("%d%d%d", &d, &x, &y);
			if ((d == 2 && x == y) || x > n || y > n || x < 1 || y < 1) {
				cnt++;
				continue;
			}
			if (d == 1) {
				if (find(x) == find(y + n) || find(y) == find(x + n))cnt++;
				else {
					unite(x, y);
					unite(x + n, y + n);
					unite(x + 2 * n, y + 2 * n);
				}
			}
			else if (d == 2) {
				if (find(y) == find(x + n) || find(y) == find(x ))cnt++;
				else {
					unite(x, y + n);
					unite(x + n, y + 2 * n);
					unite(x + 2 * n, y);
				}
			}
		}
		printf("%d\n", cnt);
	return 0;
}