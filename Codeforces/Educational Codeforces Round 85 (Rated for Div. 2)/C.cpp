#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 10;
LL a[maxn];
LL b[maxn];

LL min(LL a, LL b) {
	if (a > b) return b;
	return a;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		LL sum = 0;
		scanf("%d", &n);
		LL mmin = 1e15;
		for (int i = 0; i < n; i++) scanf("%lld%lld", &a[i], &b[i]);
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (a[0] > b[n - 1]) {
					sum += a[0] - b[n - 1];
					mmin = min(mmin, b[n - 1]);
				}
				else mmin = min(mmin, a[0]);
				
			}
			else {
				if (a[i] > b[i - 1]) {
					sum += a[i] - b[i - 1];
					mmin = min(mmin,  b[i - 1]);
				}
				else mmin = min(mmin, a[i]);
			}
		}
		printf("%lld\n", sum + mmin);
	}
	return 0;
}