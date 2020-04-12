#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;
int a[maxn];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		LL sum = 0;
		vector<LL> b;
		b.clear();
		memset(a, 0, sizeof(a));
		scanf("%d%d", &n, &x);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] >= x) {
				sum += a[i] - x;
				cnt++;
			}
			else b.push_back(x - a[i]);
		}
		sort(b.begin(), b.end());

		for (int i = 0; i < b.size(); i++) {
			if (sum >= b[i]) {
				cnt++;
				sum -= b[i];
			}
			else break;
		}
		printf("%d\n",cnt);
	}

	return 0;
}