#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int f[50][50];
int main() {
	cin.sync_with_stdio(false);
	cin >> n >> m;
	f[0][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) f[i][j] = f[i - 1][n] + f[i - 1][2];
			else if (j == n) f[i][j] = f[i - 1][1] + f[i - 1][n - 1];
			else f[i][j] = f[i - 1][j + 1] + f[i - 1][j - 1];
		}
	}
	cout << f[m][1] << endl;
	return 0;
}