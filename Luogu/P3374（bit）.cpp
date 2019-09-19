#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;
const int maxn = 500010;
int n, m;
LL a[maxn], c[maxn];

LL lowbit(LL x) {
	return x & (-x);
}
void update(LL x, LL k) {
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += k;
}

LL sum(int x) {
	LL ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		ans += c[i];
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		update(i, a[i]);
	}
	int op;
	LL l, r;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%lld%lld", &l, &r);
			update(l, r);
		}
		if (op == 2) {
			scanf("%lld%lld", &l, &r);
			printf("%lld\n", sum(r) - sum(l - 1));
		}
	}
	return 0;
}