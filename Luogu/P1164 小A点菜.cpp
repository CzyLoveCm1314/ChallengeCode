#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 110;
const int maxm = 11000;
int n, m;
int a[maxn];
int dp[maxn][maxm];

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			if (j > a[i]) dp[i][j] = dp[i - 1][j]+ dp[i - 1][j - a[i]];
			else if (j < a[i]) dp[i][j] = dp[i - 1][j];
			else if (j == a[i]) dp[i][j] = dp[i - 1][j] +1;
		}
	}
	cout << dp[n][m] << endl;

	return 0;
}