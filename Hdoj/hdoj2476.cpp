#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int dp[110][110];
int MIN(int a, int b)
{
	if (a < b)return a;
	else return b;
}
int solve(int i, int j,string a)
{
	if (dp[i][j] != -1)return dp[i][j];
	if (i > j)return  dp[i][j] = 0;
	if (i == j) return dp[i][j] = 1;
	dp[i][j] = solve(i + 1, j,a) + 1;
	for (int k = i + 1; k <= j; k++)
		if (a[k] == a[i]) dp[i][j] = MIN(solve(i + 1, k,a) + solve(k + 1, j,a), dp[i][j]);
	return dp[i][j];
}
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		memset(dp,-1, sizeof(dp));
		int i, j;
		int ans[110] = { 0 };
		for (i = 0; i < a.length(); i++)
		{
			for (j = i; j < a.length(); j++) solve(i, j, b);
		}
		for (i = 0; i<a.length(); i++)
		{
			ans[i] = dp[0][i];
			if (a[i] == b[i])
			{
				if (i == 0) ans[i] = 0;
				else ans[i] = ans[i - 1];
			}
			else
			{
				for (int j = 0; j<i; j++)
					ans[i] = MIN(ans[i], ans[j] + dp[j + 1][i]);
			}
		}
		printf("%d\n", ans[a.length() - 1]);
	}
	return 0;
}