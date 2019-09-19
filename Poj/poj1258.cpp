#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a[110][110];
bool use[110];
int mincost[110];

int prim() {
	for (int i = 0; i < n; i++) {
		use[i] = false;
		mincost[i] = a[0][i];
	}
	use[0] = true;
	mincost[0] = 0;
	int ans = 0;
	while (true) {
		int v = -1;
		for (int i = 0; i < n; i++) {
			if (!use[i] && (v == -1 || mincost[i] < mincost[v]))v = i;
		}
		if (v == -1)break;
		use[v] = true;
		ans += mincost[v];
		for (int i = 0; i < n; i++) {
			mincost[i] = min(mincost[i], a[v][i]);
		}
	}
	return ans;
}
int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)a[i][j] = 0x3f3f3f3f;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		printf("%d\n", prim());
	}
	return 0;
}