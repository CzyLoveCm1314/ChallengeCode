#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int m;
		scanf("%d", &m);
		long long ans, a, b;
		ans = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%lld%lld", &a, &b);
			ans += a*b;
		}
		printf("%lld\n", ans);
	}
	return 0;
}