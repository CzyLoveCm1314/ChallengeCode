//https://blog.csdn.net/u010372095/article/details/38474721

#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 15;
int n, m;
int G[maxn][maxn];
int dp[maxn][60000]; //3^10<60000
					 //dp[i][state]表示state状态以i点结尾的最小路径

//获取每一位的状态，返回有经过的点数
int getA(int t[], int sum) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		t[i] = sum % 3;
		sum /= 3;
		if (t[i]) k++;
	}
	return k;
}
int main() {
	int in[maxn];
	in[0] = 1;
	int three[maxn];
	for (int i = 1; i <= 10; i++)in[i] = in[i - 1] * 3;
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < in[n]; j++) dp[i][j] = -1;
			for (int j = 0; j < n; j++) G[i][j] = -1;
		}
		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			a--;
			b--;
			if (G[a][b] != -1) G[a][b] = G[b][a] = min(G[a][b], c);
			else G[a][b] = G[b][a] = c;
		}
		int minx = -1;
		//枚举已走的状态k
		for (int k = 1; k < in[n]; k++) {
			int size = getA(three, k);
			for (int i = 0; i < n; i++) {
				//以i点结尾
				if (three[i]) {
					if (size == 1) dp[i][k] = 0;
					if (dp[i][k]== -1)continue;
					if (size == n) {
						if (minx == -1) minx = dp[i][k];
						else minx = min(minx, dp[i][k]);
					}
					for (int j = 0; j < n; j++) {
						if (i != j&&three[j] < 2 && G[i][j] != -1) {
							int tk = k + in[j];
							if (dp[j][tk] == -1)dp[j][tk] = dp[i][k] + G[i][j];
							else dp[j][tk] = min(dp[i][k] + G[i][j], dp[j][tk]);
						}
					}
				}
			}
		}
		printf("%d\n", minx);
	}
	return 0;
}