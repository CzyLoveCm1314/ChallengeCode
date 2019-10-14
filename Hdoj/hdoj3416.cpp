#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2100;
const int maxm = 2000010;
int dis1[maxn];
int dis2[maxn];
struct Edge {
	int u, v, cost;
	Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[maxn];
bool vis[maxn];
int cnt[maxn];
int n,m;
int a[100010], b[100010], c[100010];

bool SPFA(int dis[], int s, int n) {
	for (int i = 0; i <= n; i++) {
		cnt[i] = 0;
		vis[i] = false;
		dis[i] = INF;
	}
	vis[s] = true;
	dis[s] = 0;
	cnt[s] = 1;
	queue<int> q;
	while (!q.empty())q.pop();
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 0; i < E[u].size(); i++) {
			int v = E[u][i].v;
			if (dis[v] > dis[u] + E[u][i].cost) {
				dis[v] = dis[u] + E[u][i].cost;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
					if (++cnt[v] > n) return false;
				}
			}
		}
	}
	return true;
}
struct Node
{
	int to, next, cap;
}edge[maxm];
int tol;
int head[maxn];
int gap[maxn], dis[maxn], pre[maxn], cur[maxn];
void init(){
	tol = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0){
	edge[tol].to = v; edge[tol].cap = w; edge[tol].next = head[u]; head[u] = tol++;
	edge[tol].to = u; edge[tol].cap = rw; edge[tol].next = head[v]; head[v] = tol++;
}

int sap(int start, int end, int nodenum){
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	memcpy(cur, head, sizeof(head));
	int u = pre[start] = start, maxflow = 0, aug = -1;
	gap[0] = nodenum;
	while (dis[start]<nodenum){
	loop:
		for (int &i = cur[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if (edge[i].cap&&dis[u] == dis[v] + 1){
				if (aug == -1 || aug>edge[i].cap) aug = edge[i].cap;
				pre[v] = u;
				u = v;
				if (v == end){
					maxflow += aug;
					for (u = pre[u]; v != start; v = u, u = pre[u]){
						edge[cur[u]].cap -= aug;
						edge[cur[u] ^ 1].cap += aug;
					}
					aug = -1;
				}
				goto loop;
			}
		}
		int mindis = nodenum;
		for (int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			if (edge[i].cap&&mindis>dis[v]){
				cur[u] = i;
				mindis = dis[v];
			}
		}
		if ((--gap[dis[u]]) == 0)break;
		gap[dis[u] = mindis + 1]++;
		u = pre[u];
	}
	return maxflow;
}

int main() {
	int t;
	int A, B;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <m; i++)scanf("%d%d%d", &a[i], &b[i], &c[i]);
		scanf("%d%d", &A, &B);
		for (int i = 0; i < m; i++) E[a[i]].push_back(Edge(b[i],c[i]));
		SPFA(dis1, A, n);
		for (int i = 0; i <= n; i++) E[i].clear();
		for (int i = 0; i <m; i++) E[b[i]].push_back(Edge(a[i], c[i]));
		SPFA(dis2, B, n);
		init();
		for (int i = 0; i<m; i++){
			if (a[i] != b[i] && dis1[a[i]] + dis2[b[i]] + c[i] == dis1[B])
				addedge(a[i], b[i], 1);
		}
		printf("%d\n", sap(A, B, n));
	}
	return 0;
}