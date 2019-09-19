#include<iostream>
#include<algorithm>
using namespace std;

int t;
int a[1010][1010];
int dp[1010][1010];

int main() {
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= i; j++) cin >> a[i][j];
	}
	for (int i = t; i >=1; i--) {
		for (int j = 1; j <= i; j++)
			dp[i][j] =a[i][j] + max(dp[i+1][j],  dp[i+1][j + 1]);
	}
	cout << dp[1][1] << endl;
	return 0;
}