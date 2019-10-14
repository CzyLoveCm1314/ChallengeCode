#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5000 + 10;
int sum[maxn << 2];
int x[maxn];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l,int r,int rt) {
	sum[rt] = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	pushup(rt);
}

void update(int p, int l, int r, int rt) {
	if (l == r) {
		sum[rt]++;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, l, m, rt << 1);
	else update(p, m+1, r, rt << 1|1);
	pushup(rt);
}

int query(int a, int b, int l, int r, int rt) {
	if (a <= l && b >= r)  return sum[rt];
	int m = (l + r) >> 1;
	int ret = 0;
	if (a <= m) ret += query(a, b, l, m, rt << 1);
	if (b > m) ret += query(a, b, m + 1, r, rt << 1 | 1);
	return ret;
}
int main(){
	int n;
	while (scanf("%d", &n) != EOF) {
		int sum = 0;
		build(0, n - 1, 1);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
			sum += query(x[i], n - 1, 0, n - 1, 1);
			update(x[i], 0, n - 1, 1);
		}
		int ans = sum;
		for (int i = 0; i < n; i++)
		{
			sum += n - x[i] - x[i] - 1;
			ans = min(ans, sum);
		}

		printf("%d\n", ans);
	}
		return 0;
}