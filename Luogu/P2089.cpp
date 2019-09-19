#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int n;
int ans[12];
int res;
vector<int> x[10000];
void dfs(int sum, int step) {
	if (step == 11) {
		if (sum == n) {
			for (int i = 1; i <= 10; i++)x[res].push_back(ans[i]);
			res++;
		}
		return;
	}
	for (int i = 1; i <= 3; i++) {
		ans[step] = i;
		dfs(sum + i, step + 1);
	}
}
int main() {
	scanf("%d", &n);
	if (n < 10 || n > 30)printf("0\n");
	else {
		dfs(0, 1);
		printf("%d\n", res);
		for (int i = 0; i < res; i++) {
			for (int j = 0; j < x[i].size(); j++) {
				if (j == 0)printf("%d", x[i][j]);
				else printf(" %d", x[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}