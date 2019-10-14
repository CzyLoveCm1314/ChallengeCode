#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 2202222;
int h, w, n;
int mx[maxn << 2];

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
	mx[rt] = w;
	if(l==r)return;
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	pushup(rt);
}

int query(int x, int l, int r, int rt) {
	if (l == r) {
		mx[rt] -= x;
		return l;
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (mx[rt<< 1 ] >= x) ret = query(x, l, m, rt<<1);
	else ret = query(x, m + 1, r, rt<<1|1);
	pushup(rt);
	return ret;
}
int main() {
	while (scanf("%d%d%d", &h, &w, &n) != EOF) {
		if (h>200000)h = 200000;
		build(1, h, 1);
		while (n--) {
			int x;
			scanf("%d", &x);
			if (mx[1] < x)printf("-1\n");
			else printf("%d\n", query(x, 1, h, 1));
		}
	}
	return 0;
}