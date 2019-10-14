#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 300 + 10;
const int inf = 0x3f3f3f3f;
int n;
int cost[maxn][maxn];
int d[maxn], inq[maxn];
void spfa(int s)   {
	memset(inq, 0, sizeof(inq));
	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (i == s){
			d[s] = inf; continue;
		}
		d[i] = cost[s][i];
		inq[i] = 1;
		q.push(i);
	}
	while (!q.empty()){
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (int i = 1; i <= n; i++){
			if (d[i]>d[u] + cost[u][i]){
				d[i] = d[u] + cost[u][i];
				if (inq[i]) continue;
				inq[i] = 1;
				q.push(i);
			}
		}
	}
}

int main(){
	while (~scanf("%d", &n)){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &cost[i][j]);
		int ans = inf;
		spfa(1);
		int loop1 = d[1];
		ans = min(ans, d[n]);
		spfa(n);
		int loopn = d[n];
		ans = min(ans, loop1 + loopn);
		printf("%d\n", ans);
	}
}
