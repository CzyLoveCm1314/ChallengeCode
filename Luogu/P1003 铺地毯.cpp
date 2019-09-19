#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10005][5];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &a[i][j]);
	int x, y;
	int flag = 0;
	scanf("%d%d", &x, &y);
	for (int i = n; i >= 1; i--) {
		if (a[i][0] <= x&&a[i][2] + a[i][0] >= x &&a[i][1] <= y&&a[i][1] + a[i][3] >= y) {
			flag = i;
			break;
		}
	}
	if (flag)printf("%d\n", flag);
	else printf("-1\n");
	return 0;
}