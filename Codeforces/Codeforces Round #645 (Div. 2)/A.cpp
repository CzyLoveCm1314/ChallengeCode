#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, k;
int div(int x) {
	if (x % 2 == 0) return x / 2;
	else return x / 2 + 1;
}
int main() {
	scanf("%d", &n);
	int a, b;
	while (n--) {
		scanf("%d%d", &a, &b);
		int t;
		if (a < b) {
			t = a;
			a = b;
			b = t;
		}
		int ans = int(a/2)*b;
		ans += (a % 2) * div(b);
		printf("%d\n", ans);
	}
	return 0;
}