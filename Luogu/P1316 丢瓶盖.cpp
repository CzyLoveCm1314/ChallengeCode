#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 1000010;
int A, B;
int a[maxn];

bool judge(int x) {
	int cnt = 1;
	int temp = a[1];
	for (int i = 2; i <= A; i++) {
		if (a[i] - temp > x) {
			cnt++;
			temp = a[i];
		}
	}
	return cnt >= B;
}
int main() {
	cin.sync_with_stdio(false);
	cin >> A >> B;
	for (int i = 1; i <= A; i++) cin >> a[i];
	sort(a + 1, a + 1 + A);
	int l = 0, r = a[A], mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (judge(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}