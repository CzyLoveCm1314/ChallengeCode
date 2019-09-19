#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;

int main() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		ans += n / i;
	}
	printf("%d\n", ans);
	return 0;
}