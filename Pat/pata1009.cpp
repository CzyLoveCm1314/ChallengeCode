#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double a[2000];
double b[2000];
double ans[10000];
int main() {
	int n;
	scanf("%d", &n);
	int t;
	double c;
	for (int i = 0; i < n; i++) {
		scanf("%d%lf", &t, &c);
		a[t] = c;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%lf", &t, &c);
		b[t] = c;
	}
	int mmax = -1;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			ans[i + j] += a[i] * b[j];
			if (ans[i + j] != 0) mmax = max(mmax, i + j);
		}
	}
	int cnt = 0;
	for (int i = mmax; i >= 0; i--) if (ans[i] != 0) cnt++;
	printf("%d", cnt);
	for (int i = mmax; i >= 0; i--) if (ans[i] != 0) printf(" %d %.1lf", i, ans[i]);

	return 0;
}