#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 100100;
typedef long long LL;
struct node {
	int l, r;
	LL sum, tag;
}tree[maxn<<2];

void push_up(int rt) {
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}
void push_down(int rt,int k) {
	tree[rt << 1].tag += k;
	tree[rt << 1].sum += k * (tree[rt << 1].r - tree[rt << 1].l + 1);
	tree[rt << 1|1].tag += k;
	tree[rt << 1|1].sum += k * (tree[rt << 1|1].r - tree[rt << 1|1].l + 1);
	tree[rt].tag = 0;
}
void update(int l, int r, int rt, int k) {
	if (l <= tree[rt].l && tree[rt].r <= r) {
		tree[rt].tag += k;
		tree[rt].sum += k * (tree[rt].r - tree[rt].l + 1);
		return;
	}
	push_down(rt, tree[rt].tag);
	int mid = (tree[rt].l + tree[rt].r) / 2;
	if (l <= mid) update(l, r, rt << 1, k);
	if (r > mid)  update(l, r, rt << 1 | 1, k);
	push_up(rt);
}
void build(int rt, int l, int r) {
	tree[rt].tag = 0;
	tree[rt].l = l;
	tree[rt].r = r;
	if (l == r) {
		scanf("%lld", &tree[rt].sum);
		return;
	}
	int mid = (l + r) / 2;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	push_up(rt);
}
LL query(int l, int r, int rt) {
	if (tree[rt].r <= r && tree[rt].l >= l) return tree[rt].sum;
	LL res = 0;
	push_down(rt,tree[rt].tag);
	int mid = (tree[rt].l + tree[rt].r) / 2;
	if (l <= mid)res += query(l, r, rt << 1);
	if (r > mid) res += query(l, r, rt << 1 | 1);
	return res;
}
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	int op, l, r;
	LL k;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%lld", &l, &r, &k);
			update(l, r, 1, k);
		}
		if (op == 2) {
			scanf("%d%d" ,&l, &r);
			printf("%lld\n", query(l, r, 1));
		}
	}
	return 0;
}