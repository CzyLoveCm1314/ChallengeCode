#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int dp[300][300];
int main() {
	cin.sync_with_stdio(false);
	cin >> n >> k;
	//dp[i][j]为 i个数分到j个盒子里
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			if (i > j) dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
			else dp[i][j] = dp[i - 1][j - 1];
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}