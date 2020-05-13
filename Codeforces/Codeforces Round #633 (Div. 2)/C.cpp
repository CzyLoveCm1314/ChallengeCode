#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

const int maxn = 100000 + 10;
int a[maxn],b[maxn];
int isok(int x,int n) {
	int t = pow(2,x-1);
	for (int k = 1; k <= x-1; k++) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				a[i + 1] += t;
			}
		}
		t /= 2;
	}
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) {
			return 0;
		}
	}
	return 1;
}
int ttime(int x) {
	int sum = 0;
	int t = 1;
	if (x == 0) return 0;
	for (int i = 1;; i++) {
		sum += t;
		if (sum >= x)return i;
		t *= 2;
	}
}
int main() {
	//cout << ttime(0) << endl;;
	int t;
	int n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int mmax = -0x3f3f3f3f;
		int mmin = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
			if (mmax < a[i])mmax = a[i];
			if (mmin > a[i]) mmin = a[i];
			
		}
		int flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				flag= 0;
			}
		}
		if (flag) printf("0\n");
		else {
			int l = 1, r = ttime(mmax - mmin);
			while (l <= r) {
				int mid = (l + r) / 2;
				if (isok(mid, n)) {
					r = mid - 1;
				}
				else l = mid + 1;
				for (int i = 0; i < n; i++)a[i] = b[i];
			}
			printf("%d\n", l);
		}
		
	}

	return 0;
}