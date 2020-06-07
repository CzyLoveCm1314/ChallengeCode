#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int maxn = 2 * 100000 + 10;
int a[maxn];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n,temp;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		int t1 = -1;
		int t2 = maxn;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			a[temp]++;
			if (temp > t1) t1 = temp;
			if (temp < t2)t2 = temp;
		}
		int mmax, cnt;
		mmax = -1;
		cnt = 0;
		for (int i = t2; i <= t1;i++) {
			if (a[i] != 0) cnt++;
			if (a[i] > mmax) mmax = a[i];
		}
		int ans1,ans2;
		if ((cnt - 1) < mmax) ans1 =cnt - 1;
		else ans1 = mmax;
		if (cnt < (mmax - 1)) ans2 =cnt;
		else ans2 = mmax-1;
		if (ans2 > ans1) printf("%d\n", ans2);
		else printf("%d\n", ans1);
	}

	return 0;
}