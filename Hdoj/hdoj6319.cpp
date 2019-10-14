#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const int maxn = 1e7 + 10;

int a[maxn];
int n, m, k, p, q, r, mod;
int Q[maxn];
int head, tail;
LL res1, res2;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &mod);
		for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
		for (int i = k + 1; i <= n; i++) a[i] = (1ll*p*a[i - 1] + 1ll*q*i + r) % mod;

		head = 1, tail = 0;
		res1 = res2 = 0;
		for (int i = n; i > 0; i--) {
			while (tail >= head&&a[Q[tail]] <= a[i]) tail--;
			Q[++tail] = i;
			if (i + m - 1 <= n) {
				while (Q[head] >= i + m) head++;
				res1 += i^a[Q[head]];
				res2 += i ^ (tail - head + 1);
			}
		}
		printf("%lld %lld\n", res1, res2);
	}
	return 0;
}