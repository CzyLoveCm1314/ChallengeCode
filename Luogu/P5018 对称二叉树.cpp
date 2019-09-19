#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int maxn = 1000100;
struct node {
	int ls, rs, val, sum;
}a[maxn];
int n;
int dfs(int x) {
	int ans = 1;
	if (a[x].ls != -1) ans += dfs(a[x].ls);
	if (a[x].rs != -1) ans += dfs(a[x].rs);
	a[x].sum = ans;
	return ans;
}
bool check(int u,int v) {
	if (u == -1 && v == -1) return true;
	if (u!=-1 && v!=-1 && a[u].sum == a[v].sum && a[v].val == a[u].val &&
		check(a[u].ls,a[v].rs) && check(a[u].rs,a[v].ls)) return true;
	return false;
}
int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].val;
	for (int i = 1; i <= n; i++) cin >> a[i].ls >> a[i].rs;
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (check(a[i].ls,a[i].rs)) ans = max(ans, a[i].sum);
	cout << ans << endl;
	return 0;
}