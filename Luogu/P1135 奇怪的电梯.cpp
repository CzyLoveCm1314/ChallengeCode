#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 300;
int n, A, B;
int a[maxn];
int dp[maxn];
int main() {
	cin.sync_with_stdio(false);
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++)cin >> a[i];
	dp[A] = 1;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 1; i <= n; i++) {
			if (dp[i] > 0) {
				if (i + a[i] <= n && (dp[i + a[i]] == 0 || dp[i + a[i]]>dp[i] + 1)) {
					dp[i + a[i]] = dp[i] + 1;
					flag = true;
				}
				if (i - a[i] >=1 && (dp[i - a[i]] == 0 || dp[i - a[i]]>dp[i] + 1)) {
					dp[i - a[i]] = dp[i] + 1;
					flag = true;
				}
			}
		}
	}
	cout << dp[B]-1<<endl;
	return 0;
}