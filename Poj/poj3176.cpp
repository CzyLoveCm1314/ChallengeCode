#include<iostream>
using namespace std;
int num[351][351];
int dp[351][351];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int i, j;
		for (i = 0; i < 351; i++)
		{
			for (j = 0; j < 351; j++)
			{
				num[i][j]=0;
				dp[i][j] = 0;
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= i; j++)
			{
				cin >> num[i][j];
			}
		}
		for (i = n; i >= 1; i--)
		{
			for (j = 1; j <= i; j++)
			{
				dp[i][j] = max(dp[i +1][j], dp[i + 1][j + 1]) + num[i][j];
			}
		}
		cout << dp[1][1] << endl;
	}
	return 0;
}