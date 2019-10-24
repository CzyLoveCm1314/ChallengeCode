#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 11000;
int n, m;
int num[1010], vis[1010];

struct person {
	string t;
	int gra;
}a[maxn];
bool cmp(person a, person b) {
	if (a.t[0] != b.t[0]) return a.t[0] < b.t[0];
	else if (a.gra!=b.gra) return a.gra > b.gra;
	else return a.t < b.t;
}
int str2int(string a) {
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans = ans *10+ a[i] - '0';
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) cin >> a[i].t >> a[i].gra;
	sort(a, a + n, cmp);
	int op;
	char c1, c2;
	int cnt;
	string temp;
	for (int i = 0; i < n; i++) {
		int x = str2int(a[i].t.substr(1, 3));
		vis[x]++;
		num[x] += a[i].gra;
	}
	for (int k = 1; k <= m; k++) {
		scanf("%d", &op);
		if (op == 1) {
			getchar();
			scanf("%c", &c1);
			bool flag = false;
			printf("Case %d: %d %c\n", k, op, c1);
			for (int i = 0; i < n; i++) {
				if (a[i].t[0] == c1) {
					cout << a[i].t << ' ' << a[i].gra << endl;
					flag = true;
				}
			}
			if (!flag)printf("NA\n");
		}
		else if (op == 2) {
			scanf("%d", &cnt);
			printf("Case %d: %d %03d\n", k, op, cnt);
			if (vis[cnt] > 0) printf("%d %d\n", vis[cnt], num[cnt]);
			else printf("NA\n");
		}
		else {
			cin >> temp;
			printf("Case %d: %d ", k, op);
			cout << temp << endl;
			int cntt[1100] = { 0 };
			bool flag = false;
			int maxx = -1;
			for (int i = 0; i < n; i++) {
				if (a[i].t.substr(4, 6) == temp) {
					int ttt = str2int(a[i].t.substr(1,3));
					cntt[ttt]++;
					flag = true;
					if (cntt[ttt]>maxx) maxx = cntt[ttt];
				}
			}
			for (int i = maxx; i > 0; i--) {
				for (int j = 0; j < 1000;j++) {
					if (cntt[j]==i) printf("%d %d\n", j, cntt[j]);
				}
			}
			if(!flag) printf("NA\n");
		}
	}
	return 0;
}