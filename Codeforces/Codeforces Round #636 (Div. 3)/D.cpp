#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 2 * 100000 + 10;
int a[maxn];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		vector<int> v;
		for (int i = 0; i < n / 2; i++) {
			v.push_back(a[i] + a[n - 1 - i]);
		}
		sort(v.begin(), v.end());

	}
	return 0;
}