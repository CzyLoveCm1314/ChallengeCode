#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxm = 31000;
const int maxn = 30;
int v[maxn], w[maxn], dp[maxn][maxm];

int main() {
	int n, m;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)cin >> v[i] >> w[i];
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 0; j--) {
			if(j>=v[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i] * w[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[m][n] << endl;
	return 0;
}