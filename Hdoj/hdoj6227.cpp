#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		int a[1000] = { 0 };
		int b[1000] = { 0 };
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			b[i - 1] = a[i] - a[i - 1] - 1;
			ans += b[i - 1];
		}
		int temp = min(b[1], b[n - 1]);
		printf("%d\n", ans - temp);
	}
	return 0;
}