#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 1000001
int n;
struct node {
	int max, min, data;
}cal[maxn<<2];

int a[maxn];
int MAX[maxn];
int MIN[maxn];
int cnt;

void build(int l,int r,int rt) {
	if (l == r) {
		scanf("%d", &cal[rt].data);
		cal[rt].max = cal[rt].min = cal[rt].data;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	if (cal[rt << 1].max > cal[rt << 1 | 1].max) cal[rt].max = cal[rt << 1].max;
	else cal[rt].max = cal[rt << 1 | 1].max;
	if (cal[rt << 1].min < cal[rt << 1 | 1].min) cal[rt].min = cal[rt << 1].min;
	else cal[rt].min = cal[rt << 1 | 1].min;
}

int querymax(int a, int b, int rt,int l,int r) {
	if (r < a || b < l) return -0x3f3f3f3f;
	if (a <= l && r <= b) return cal[rt].max;
	else {
		int m = (l + r) >> 1;
		int vl = querymax(a, b, rt << 1, l, m);
		int vr = querymax(a, b, rt << 1|1, m + 1, r);
		//printf("max: %d %d %d %d %d %d\n", l, m, vl, m + 1, r, vr);
		if (vl > vr) return vl;
		else return vr;
	}
}

int querymin(int a, int b, int rt, int l, int r) {
	if (r < a || b < l) return 0x3f3f3f3f;
	if (a <= l&&r <= b) return cal[rt].min;
	else {
		int m = (l + r) >> 1;
		int vl = querymin(a, b, rt << 1, l, m);
		int vr = querymin(a, b, rt << 1|1, m + 1, r);
		if (vl < vr) return vl;
		else return vr;
	}
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	build(1, n, 1);
	cnt = 1;
	//printf("%d %d %d\n", cal[1].max, cal[1].min, cal[1].data);
	for (int i = 1; i <= n - k + 1; i++)
	{ 
		MAX[cnt] = querymax(i, k+i-1, 1, 1, n);
		MIN[cnt++]=querymin(i, k+i-1, 1, 1, n);
	}
	printf("%d", MIN[1]);
	for (int i = 2; i < cnt; i++) printf(" %d", MIN[i]);
	printf("\n");
	printf("%d", MAX[1]);
	for (int i = 2; i < cnt; i++) printf(" %d", MAX[i]);
	printf("\n");
	return 0;
}