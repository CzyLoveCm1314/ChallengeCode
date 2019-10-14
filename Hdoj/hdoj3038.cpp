#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 200000 + 10;

int fa[maxn], a[maxn];
int ran[maxn];
int dis[maxn];
int ans;
void init() {
	int i;
	for (i = 1; i < maxn; i++) {
		fa[i] = i;
		ran[i] = 0;
		dis[i] = 0;
	}
	ans = 0;
}

int find(int a) {
	if (a == fa[a])  return a;    
	else { 
		int pa = fa[a];        
		fa[a] = find(fa[a]);
		dis[a] += dis[pa];
		return fa[a]; 
	}

}

void unite(int a, int b,int s) {
	int pa = find(a); 
	int pb = find(b);    
	if (pa == pb) { 
		if (dis[a] - dis[b] + s != 0) ans++; 
	}
	else { 
		fa[pb] = pa;        
		dis[pb] = dis[a] - dis[b] + s;
	}
}


int n, m;

int main() {
	while (~scanf("%d%d", &n, &m)) {
		init();
		int a, b, c;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			unite(a, b + 1, c);
		}
		printf("%d\n", ans);
	}
	return 0;
}