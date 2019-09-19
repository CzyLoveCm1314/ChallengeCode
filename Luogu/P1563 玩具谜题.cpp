#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 110000;
int n, m;
struct person {
	int dir;
	string name;
}a[maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)cin >> a[i].dir >> a[i].name;
	int dir, cnt;
	int j = 0;
	while (m--) {
		scanf("%d%d", &dir, &cnt);
		if (a[j].dir == 0) {
			if (dir == 0)cnt = -cnt;
		}
		else {
			if (dir == 1)cnt = -cnt;
		}
		if (j + cnt < 0) {
			j = (j + cnt) % n + n;
		}
		else j = (j+cnt)%n;
	}
	cout << a[j].name << endl;
	return 0;
}