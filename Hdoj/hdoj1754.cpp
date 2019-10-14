#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 200010
int mx[maxn << 2];
void pushup(int rt) {
	if (mx[rt << 1] > mx[rt << 1 | 1]) mx[rt] = mx[rt << 1];
	else mx[rt] = mx[rt << 1 | 1];
}
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &mx[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	pushup(rt);
}

void update(int p, int add, int l, int r, int rt) {
	if (l == r) {
		mx[rt] = add;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, add, l, m, rt << 1);
	else update(p, add, m + 1, r, rt << 1 | 1);
	pushup(rt);
}

int query(int a, int b, int l, int r, int rt) {
	if (a <= l && b >= r) return mx[rt];
	int m = (l + r) >> 1;
	int ret = 0;
	if (a <= m) ret = max(ret, query(a, b, l,m,rt<<1));
	if (b > m) ret = max(ret, query(a, b, m+1,r,rt<<1|1));
	return ret;
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		build(1, n, 1);
		char op[10] = { 0 }; 
		int a, b;
		while (m--) {
			scanf("%s%d%d", op, &a, &b);
			if (op[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
			else update(a, b, 1, n, 1);
		}
	}
	return 0;
}