#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 200000 + 10;
int mx[maxn<<2];
int ans[maxn];
int a[maxn], b[maxn];
void build(int l, int r, int rt) {
	if (l == r) {
		mx[rt] = 1;
		return;
	}
	int m = (r + l) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	mx[rt] = mx[rt << 1] + mx[rt << 1 | 1];
}

void update(int x, int add, int l, int r, int rt) {
	mx[rt]--;
	if (l == r) {
		ans[l] = add;
		return;
	}
	int m = (l + r) >> 1;
	if (x <= mx[rt << 1])update(x, add, l, m, rt << 1);
	else update(x-mx[rt<<1], add, m+1, r, rt << 1|1);
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i], &b[i]);
		}
		build(1, n, 1);
		for (int i = n; i >0; i--) update(a[i]+1, b[i], 1, n, 1);
		printf("%d", ans[1]);
		for (int i = 2; i <= n; i++)printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}