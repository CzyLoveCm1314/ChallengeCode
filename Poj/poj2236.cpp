#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 50000 + 10;

int fa[maxn], a[maxn];
int ran[maxn];
struct computer {
	int x, y, flag;
}c[maxn];
void init() {
	int i;
	for (i = 1; i < maxn; i++) {
		fa[i] = i;
		ran[i] = 0;
		c[i].flag = 0;
	}
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int a, int b) {
	int r1 = find(a);
	int r2 = find(b);
	if (r1 == r2) return;
	if (ran[r1] < ran[r2]) fa[r1] = r2;
	else {
		fa[r2] = r1;
		if (ran[r1] == ran[r2]) ran[r1]++;
	}
}
double dis(computer a, computer b) {
	return sqrt((double)(a.x - b.x)*(double)(a.x - b.x) + (double)(a.y - b.y)*(double)(a.y - b.y));
}
int n, d;
int main(){
	while (~scanf("%d%d", &n, &d)) {
		init();
		for (int i = 1; i <= n; i++) scanf("%d%d", &c[i].x, &c[i].y);
		char op[10];
		int p, q;
		while (~scanf("%s", op)) {
			if (op[0] == 'O') {
				scanf("%d", &p);
				c[p].flag = 1;
				for (int i = 1; i <= n; i++) {
					if (c[i].flag == 1 && dis(c[p], c[i]) <= d) unite(p, i);
				}
			}
			else {
				scanf("%d%d", &p, &q);
				if (find(p) == find(q))printf("SUCCESS\n");
				else printf("FAIL\n");
			}
		}

	}
	return 0;
}