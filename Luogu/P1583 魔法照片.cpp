#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 20100;
int n, k;
int e[12];
struct person {
	int c, d, id, id2;
	bool operator <(const person &x) const {
		if (c != x.c) return c>x.c;
		else return id < x.id;
	}
}a[maxn];
int main() {
	cin.sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= 10; i++) cin >> e[i];
	for (int i = 1; i <= n; i++) {
		cin >> a[i].c;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		a[i].id2 = i;
		a[i].c += e[(a[i].id2 - 1) % 10 + 1];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= k; i++) {
		if (i == 1) cout << a[i].id;
		else cout << ' ' << a[i].id;
	}

	return 0;
}