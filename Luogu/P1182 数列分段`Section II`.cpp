#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100100;
int a[maxn], n, m;
int l, r;
bool judge(int x) {
	int total = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (total + a[i] <= x)total += a[i];
		else{
			total = a[i];
			cnt++;
		}
	}
	if (cnt >= m) return true;
	return false;
}
int main() {
	cin >> n >> m;
	l = 0;
	r = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = max(l, a[i]);
		r = r + a[i];
	}
	int mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (judge(mid)) l = mid+1;
		else r = mid-1;
	}
	cout << l << endl;

	return 0;
}