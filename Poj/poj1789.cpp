#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

const int maxn = 2100;
const int INF = 0x3f3f3f3f;
string str[maxn];
int n;
bool vis[maxn];
int map[maxn][maxn];
int mincost[maxn];

int getdiff(string a, string b) {
	int ans = 0;
	for (int i = 0; i < a.size(); i++) if (a[i] != b[i])ans++;
	return ans;
}

int prim() {
	for (int i = 0; i < n; i++) {
		mincost[i] = map[0][i];
		vis[i] = false;
	}
	vis[0] = true;
	mincost[0] = 0;
	int ans = 0;
	while (true) {
		int v = -1;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && (v == -1 || mincost[i] < mincost[v]))v = i;
		}
		if (v == -1)break;
		vis[v] = true;
		ans += mincost[v];
		for (int i = 0; i < n; i++)mincost[i] = min(mincost[i], map[v][i]);
	}
	return ans;
}
int main() {
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++ ) cin >> str[i];
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				map[i][j] = map[j][i] = INF;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) 
				map[i][j] = map[j][i] = getdiff(str[i], str[j]);
		printf("The highest possible quality is 1/%d.\n", prim());
	}
	return 0;
}