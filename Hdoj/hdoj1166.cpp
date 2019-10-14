#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50010
struct node {
	int sum;
}cal[maxn<<2];

void pushup(int rt) {
	cal[rt].sum = cal[rt << 1].sum + cal[rt << 1 | 1].sum;
}

void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &cal[rt].sum);
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	pushup(rt);
}

void update(int p, int add, int l, int r, int rt) {
	if (l == r) {
		cal[rt].sum += add;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, add, l, m, rt << 1);
	else update(p, add, m + 1, r, rt << 1 | 1);
	pushup(rt);
}
int query(int a, int b, int rt, int l, int r) {
	if (a <= l && b >= r) return cal[rt].sum;
	int m = (l + r) >> 1;
	int ret = 0;
	if(a<=m) ret += query(a, b, rt << 1, l, m);
	if(b>m) ret += query(a, b, rt << 1 | 1, m + 1, r);
	return ret;
}
int main() {
	int t;
	int cnt = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		build(1, n, 1);
		char op[10] = { 0 };
		printf("Case %d:\n", cnt++);
		while (scanf("%s", op) != EOF) {
			if (op[0] == 'E') break;
			int a, b;
			scanf("%d%d", &a, &b);
			if (op[0] == 'Q') {
				printf("%d\n", query(a, b, 1, 1, n));
			}
			if (op[0] == 'S') update(a, -b, 1, n, 1);
			if (op[0] == 'A') update(a, b, 1, n, 1);
		}
	}

	return 0;
}