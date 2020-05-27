#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100000 + 10;
int n, k, t;
int a[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);	
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] <= i) ans = i;
		}
		printf("%d\n", ans+1);
	}
	return 0;
}