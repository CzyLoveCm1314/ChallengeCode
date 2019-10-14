#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1010000;

int n, x, y;
struct Edge {
	int u, v; 
	int cost; 
	Edge(int _u = 0, int _v = 0, int _cost = 0) :u(_u), v(_v), cost(_cost) {}
}; 
vector<Edge> E;
int dist[maxn];
int bellman_ford(int start, int n) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[start] = 0;
	for(int i= 1; i< n; i++){
		bool flag=false;
		for(int j=0;j<E.size();j++){
			int u=E[j].u;
			int v=E[j].v;
			int cost=E[j].cost;
			if(dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost; 
				flag=true;
			}
		} 
	}
	for(int j=0;j<E.size();j++)
		if(dist[E[j].v]>dist[E[j].u]+E[j].cost)
			return -1;
	if (dist[n] == INF) return -2;
	return dist[n];
} 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		E.clear();
		scanf("%d%d%d", &n, &x, &y);
		int a, b, c;
		for (int i = 1; i <= x; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (a > b) swap(a, b);
			E.push_back(Edge(a, b, c));
		}
		for (int i = 1; i <= y; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (a > b) swap(a, b);
			E.push_back(Edge(b, a, -c));
		}
		printf("%d\n", bellman_ford(1, n));
	}
	return 0;
}