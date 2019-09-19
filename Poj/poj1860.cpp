#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 220;
struct edge {
	int a;      
	int b;     
	double r;   
	double c;  
}e[maxn<<1];
double dis[maxn];
int n, m, s;
double v;
int cnt = 0;

bool bellman() {
	memset(dis, 0, sizeof(dis));  
	dis[s] = v;
	bool update;
	for (int i = 1; i <= n - 1; i++) {
		update = false;
		for (int j = 0; j < cnt; j++) {
			if (dis[e[j].b] < (dis[e[j].a] - e[j].c)*e[j].r) {
				dis[e[j].b] = (dis[e[j].a] - e[j].c)*e[j].r;
				update = true;
			}	
		}
		if (!update)break;
	}
	for (int j = 0; j < cnt; j++) {
		if (dis[e[j].b] < (dis[e[j].a] - e[j].c)*e[j].r) {
			return true;
		}
	}
	return false;
}
int main() {
	while (~scanf("%d%d%d%lf", &n, &m, &s, &v)) {
		memset(e, 0, sizeof(e));
		for (int i = 0; i < m; i++) {
			int a, b;
			double rab, cab, rba, cba;
			scanf("%d%d%lf%lf%lf%lf", &a, &b, &rab, &cab, &rba, &cba);
			e[cnt].a = a;
			e[cnt].b = b;
			e[cnt].r = rab;
			e[cnt++].c = cab;
			e[cnt].a = b;
			e[cnt].b = a;
			e[cnt].r = rba;
			e[cnt++].c = cba;
		}
		if (bellman())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}