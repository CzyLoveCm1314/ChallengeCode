#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int main() {
	
	int t;
	long long n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n % 4 != 0) printf("NO\n");
		else {
			printf("YES\n");
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				if (i == 1) printf("%d", 2 * i);
				else printf(" %d", 2 * i);
				ans += 2 * i;
			}
			int cnt = 1;
			for (int i = 1; i <= n / 2; i++) {
				if(i==n/2) printf(" %d", ans);
				else printf(" %d",cnt);
				ans -= cnt;
				cnt += 2;
			}
			printf("\n");
		}
	}
	return 0;
}