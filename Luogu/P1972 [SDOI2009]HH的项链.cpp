#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000010;
int n,m;
int a[maxn];
int c[maxn];
int vis[maxn];
int ans[maxn];

struct node {
	int l, r;
	int pos;
	const int operator <(const node &x) {
		return r < x.r;
	}
}q[maxn];

int lowbit(int x) {
	return x&-x;
}

void update(int cnt, int x) {
	for (int i = cnt; i <= n; i += lowbit(i))
		c[i] += x;
}

int getsum(int cnt) {
	int ans = 0;
	for (int i = cnt; i >= 1; i -= lowbit(i))
		ans += c[i];
	return ans;
}
int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].pos = i;
	}
	sort(q + 1, q + 1 + m);
	int next = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = next; j <= q[i].r; j++) {
			if (vis[a[j]]) {
				update(vis[a[j]], -1);
			}
			update(j, 1);
			vis[a[j]] = j;
		}
		next = q[i].r + 1;
		ans[q[i].pos] = getsum(q[i].r) - getsum(q[i].l - 1);
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}