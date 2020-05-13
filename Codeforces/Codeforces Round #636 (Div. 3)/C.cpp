#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long LL;
const int maxn = 2 * 100000 + 10;
LL a[maxn];

int main() {
	int t;
	int n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)scanf("%lld", &a[i]);
		LL ans = 0;
		int i = 0;
		int flag = 1;
		if (a[i] < 0)flag = -1;
		else flag = 1;
		while (i < n) {
			if (flag == 1) {
				LL t = a[i];
				while (i < n && a[i]>0) {
					if (a[i] > t)t = a[i];
					i++;
				}
				ans += t;
				flag = -1;
			}
			else if (flag == -1) {
				LL t = a[i];
				while (i < n && a[i] < 0) {
					if (a[i] > t)t = a[i];
					i++;
				}
				ans += t;
				flag = 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}