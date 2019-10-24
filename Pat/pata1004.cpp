#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct node {
	int father;
	int level;
	vector<int> sons;
}a[2000];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int temp, cnt, t;
	for (int i = 0; i < 2000; i++) {
		a[i].father = 0;
		a[i].level = 0;
		a[i].sons.clear();
	}
	if (n == 1 && m == 0)printf("1");
	int mmax = -1;
	for (int k = 0; k < m;k++) {
		scanf("%d%d", &temp, &cnt);
		for (int i = 0; i < cnt; i++) {
			scanf("%d", &t);
			a[temp].sons.push_back(t);
			a[t].father = temp;
		}
	}

	queue<int> q;
	q.push(1);
	a[1].level = 0;
	int vis[2000] = { 0 };
	vis[1] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < a[t].sons.size(); i++) {
			if (!vis[a[t].sons[i]]) {
				vis[a[t].sons[i]]=1;
				a[a[t].sons[i]].level = a[t].level + 1;
				mmax = max(a[a[t].sons[i]].level, mmax);
				q.push(a[t].sons[i]);
			}
		}
	}

	for (int i = 0; i <= mmax; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j].level == i && !a[j].sons.size())
				cnt++;
		}
		if (i == 0) printf("%d", cnt);
		else printf(" %d", cnt);
	}
	printf("\n");
	return 0;
}