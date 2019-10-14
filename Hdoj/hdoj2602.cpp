//hdu2062
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int max(int  x, int y){
	return x > y ? x : y;
}

#define maxn 1005
int volume[maxn];
int dp[maxn][maxn];
int value[maxn];

int main()
{
	int t, n, v, i, j;
	scanf("%d", &t);
	while (t--){
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &v);
		for (i = 1; i <= n; i++) scanf("%d", &value[i]);
		for (i = 1; i <= n; i++) scanf("%d", &volume[i]);	
		for (i = 1; i <= n; i++){
			for (j = 0; j <=v; j++){
				if (j >= volume[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - volume[i]] + value[i]);
				else dp[i][j] = dp[i - 1][j];
			}
		}
		printf("%d\n", dp[n][v]);
	}
	return 0;
}