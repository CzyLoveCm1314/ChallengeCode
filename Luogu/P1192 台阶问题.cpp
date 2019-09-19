#include<iostream>
using namespace std;

const int maxn = 100010;
int a[maxn], n, k;
int main() {
	cin.sync_with_stdio(false);
	cin >> n >> k;
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++){
			if (i - j >= 0) {
				a[i] =(a[i]+a[i - j])% 100003;
			}
		}
	}
	cout << a[n] << endl;
	return 0;
}