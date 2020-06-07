#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 100000 + 10;
typedef long long ll;
int n, k, t;


int main() {
	scanf("%d", &t);
	ll x1, x2, y1, y2;
	ll ans = 0;
	while (t--) {
		scanf("%lld%lld%lld%lld", &x1,&y1,&x2,&y2);
		ans = 1 + (y2 - y1) * (x2 - x1);
		printf("%lld\n", ans);
	}
	return 0;
}