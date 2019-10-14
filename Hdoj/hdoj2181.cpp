#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 25;
struct Edge {
	int v, cost;
	Edge(){}
	Edge(int _v,int _cost):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
int vis[maxn];
int m, cnt;
int ans[maxn];

void dfs(int x,int k) {
	vis[x] = 1;
	ans[k] = x;
	if (k == 20) {
		int flag = 0;
		for (int i = 0; i < E[x].size(); i++) {
			int v = E[x][i].v;
			if (v == m) flag = 1;
		}
		if (flag) {
			printf("%d:  %d", cnt++, ans[1]);
			for (int i = 2; i <= 20; i++)printf(" %d", ans[i]);
			printf(" %d\n", m);
		}
		else return;
	}
	for (int i = 0; i < E[x].size(); i++) {
		int v = E[x][i].v;
		if (!vis[v]) {
			dfs(v, k + 1);
			vis[v] = 0;
		}
	}
}
int main(){
	int a;
	for (int i = 1; i <= 20; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a);
			E[i].push_back(Edge(a, 1));
		}
	}

	while (~scanf("%d", &m)) {
		if (m <= 0)break;
		cnt = 1;
		dfs(m,1);
	}
	return 0;
}