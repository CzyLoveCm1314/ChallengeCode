#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 800;
const int INF = 0x3f3f3f3f;

struct node {
	double x, y;
	node(){}
	node(int _x,int _y):x(_x),y(_y){}
}a[maxn];

struct Edge {
	int u,v;
	double w;
	Edge() {}
	Edge(int _u,int _v,double _w):u(_u),v(_v),w(_w){}
};
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
Edge E[1500000-1];
int fa[maxn];
int ran[maxn];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x]=find(fa[x]);
}

void unite(int xx, int yy) {
	int x = find(xx);
	int y = find(yy);
	if (x == y) return;
	if (ran[x] < ran[y]) {
		fa[x] = y;
	}
	else {
		fa[y] = x;
		if (ran[x] == ran[y])ran[x]++;
	}
}

int  main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &a[i].x, &a[i].y);
		fa[i] = i;
		ran[i] = 0;
	}
	int cnt = 0;
	double dis;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				dis = (a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y);
				E[cnt++] = Edge(i, j, dis);
			}
		}
	}
	scanf("%d", &m);
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		E[cnt++]=Edge(u-1, v-1, 0);
		E[cnt++]=Edge(v-1 ,u-1, 0);
	}
	sort(E, E + cnt, cmp);
	int tt = 0;
	for (int i = 0; i < cnt; i++) {
		if (find(E[i].u) != find(E[i].v)){
			unite(E[i].u, E[i].v);
			if(E[i].w!=0) printf("%d %d\n", E[i].u+1, E[i].v+1);
			if (++tt >= n - 1)break;
		}
	}
	return 0;
}