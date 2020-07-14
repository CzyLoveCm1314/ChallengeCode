#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 25;
int a, b, c;
int ans[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) {
		if (vis[20][20][20]) return ans[20][20][20];
		else {
			int temp = w(20, 20, 20);
			vis[20][20][20] = true;
			ans[20][20][20] = temp;
			return temp;
		}
	}
	else if (a < b && b < c) {
		if (vis[a][b][c]) return ans[a][b][c];
		else {
			int temp = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
			vis[a][b][c] = true;
			ans[a][b][c] = temp;
			return temp;
		}
	}
	else {
		if (vis[a][b][c]) return ans[a][b][c];
		else {
			int temp = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
			vis[a][b][c] = true;
			ans[a][b][c] = temp;
			return temp;
		}
	}
}
int main() {
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	return 0;
}