#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;
const int maxn = 500010;
int n, m;
LL c[maxn];

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
	LL last, now;
	last = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &now);
		update(i, now-last);
		last = now;
	}
	int op;
	LL l, r,k;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%lld%lld%lld", &l, &r,&k);
			update(l, k);
			update(r+1, -k);
		}
		if (op == 2) {
			scanf("%lld", &k);
			printf("%lld\n", sum(k));
		}
	}
	return 0;
}