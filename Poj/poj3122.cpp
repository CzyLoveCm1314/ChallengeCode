#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 10000 + 10;
const double pi = acos(-1.0);
int n, f;
double a[maxn], temp;

bool check(double x) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += int(a[i] / x);
	}
	return ans >= (f + 1);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &f);
		double m = -1;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &temp);
			a[i] = pi * temp * temp;
			if (temp > m)m = temp;
		}
		double l = 0;
		double r = m * m * pi;
		double mid;
		for (int i = 0; i < 100; i++) {
			mid = (l + r) / 2;
			if (check(mid))l = mid;
			else r = mid;
		}
		printf("%.4lf\n", mid);
	}
	return 0;
}