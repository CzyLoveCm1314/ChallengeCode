#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int INF = 0x7fffffff;
const int maxn = 2000;

struct Edge {
	int v; 
	int cost;
	Edge(int _v = 0, int _cost = 0) :v(_v), cost(_cost) {}
};
vector<Edge>E[maxn];
bool vis[maxn];
int cnt[maxn];
int dist[maxn];

bool SPFA(int start,int n){
	memset(vis,false,sizeof(vis));
	for( int i = 0;i <= n; i++ ) dist[i]=INF;
	vis[start]=true; 
	dist[start]=0;
	queue<int>que;
	while(!que.empty())que.pop();
	que.push(start);
	memset(cnt,0,sizeof(cnt));
	cnt[start]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop(); 
		vis[u]=false;
		for(int i=0;i<E[u].size();i++){ 
			int v=E[u][i].v; 
			if(dist[v]>dist[u]+E[u][i].cost){
				dist[v]=dist[u]+E[u][i].cost;
				if(!vis[v]){
					vis[v]=true;
					que.push(v); 
					if(++cnt[v]>n) return false; 
				} 
			} 
		} 
	} 
	return true; 
}

int n, d;
struct house {
	int height, id;
	bool operator<(const house a)const {
		return height < a.height;
	}
}h[maxn];
int main() {
	int tt;
	scanf("%d", &tt);
	for (int k = 1; k <= tt;k++) {
		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; i++) {
			scanf("%d", &h[i].height);
			h[i].id = i;
			E[i].clear();
		}
		sort(h, h + n);
		for (int i = 0; i < n - 1; i++) {
			E[i + 1].push_back(Edge(i, -1));
			if ( h[i].id > h[i + 1].id ) 
				E[h[i+1].id].push_back(Edge(h[i].id, d));
			else E[h[i].id].push_back(Edge(h[i + 1].id, d));
		}
		int s, t;
		s = min(h[0].id, h[n - 1].id);
		t = max(h[0].id, h[n - 1].id);

		printf("Case %d: ", k);
		if(SPFA(s, n))
			printf("%d\n", dist[t]);
		else printf("-1\n");
	}
	return 0;
}