#include<iostream>
using namespace std;

int a[150];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int now = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > now) ans += (a[i] - now) * 6 + 5;
		else  ans += (now - a[i]) * 4 + 5;
		now = a[i];
	}
	printf("%d\n", ans);
	return 0;
}