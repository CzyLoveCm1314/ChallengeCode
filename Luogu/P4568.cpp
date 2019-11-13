#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN = 2000000 + 10;
const int MINN = 10010;
const int INF = 1e9 + 7;
int dis[MINN][20], fist[MAXN], nxt[MAXN];
bool vis[MINN][20];
int temp, ans, n, m, k, star, eend, xa, xb, xc;
struct edge{
	int u, v, w;
	edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
	edge(){}
}line[MAXN];

void build(int x, int y, int z){
	line[++temp] = edge(x,y,z);
	nxt[temp] = fist[x];
	fist[x] = temp;
}
struct zt{
	int from;
	int diss;
	int rank;
	zt(int _from, int _diss, int _rank) :from(_from), diss(_diss), rank(_rank) {}
	zt(){}
};
priority_queue<zt> q;
bool operator < (zt a, zt b){
	return a.diss > b.diss;//Ð¡¸ù¶Ñ 
}
void heap_dijkstra(){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push(zt(star, 0, 0));
	dis[star][0] = 0;
	while (!q.empty()){
		zt t = q.top();
		q.pop();
		int t1 = t.from, t2 = t.rank;
		if (vis[t1][t2]) continue;
		vis[t1][t2] = true;
		for (int i = fist[t1]; i != -1; i = nxt[i]){
			int z = line[i].v;
			if (dis[z][t2] > dis[t1][t2] + line[i].w &&!vis[z][t2]){
				dis[z][t2] = dis[t1][t2] + line[i].w;
				q.push(zt( z, dis[z][t2], t2));
			}
			if (t2 + 1 <= k && !vis[z][t2+1] && dis[z][t2 + 1] > dis[t1][t2]){
				dis[z][t2 + 1] = dis[t1][t2];
				q.push(zt(z, dis[z][t2 + 1], t2 + 1));
			}
		}
	}
}
int main()
{
	ans = 0x3f3f3f3f;
	memset(fist, -1, sizeof(fist));
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &star, &eend);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &xa, &xb, &xc);
		build(xa, xb, xc);
		build(xb, xa, xc);
	}
	heap_dijkstra();
	for (int i = 0; i <= k; ++i)
		ans = min(ans, dis[eend][i]);
	printf("%d\n", ans);
	return 0;
}
