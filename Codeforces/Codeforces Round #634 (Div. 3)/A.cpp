#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans;
		if (n % 2 == 0) ans = n / 2 - 1;
		else {
			ans = (n + 1) / 2 - 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}