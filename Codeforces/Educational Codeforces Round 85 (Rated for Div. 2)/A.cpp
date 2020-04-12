#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 200;
int p[maxn], c[maxn];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int flag = 1;
		for (int i = 0; i < n; i++) scanf("%d%d", &p[i], &c[i]);
		int tp = p[0], tc = c[0];
		if (tp < tc) flag = 0;
		for (int i = 1; i < n; i++) {
			if (flag) {
				if (tp < tc || (p[i] - tp <  c[i]-tc ))  flag = 0;
				if (p[i] >= tp) tp = p[i];
				else flag = 0;
				if (c[i] >= tc) tc = c[i];
				else flag = 0;
			}
			else break;
		}
		if (tp < tc) flag = 0;
		if (flag) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}