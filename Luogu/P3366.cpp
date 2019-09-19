#include<bits/stdc++.h>

const int maxn=5010;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];

int prim(int n) {
	int lowcost[maxn];
	bool vis[maxn];
	memset(lowcost, 0x3f, sizeof(lowcost));
	memset(vis, false, sizeof(vis));
	int sum = 0;
	for (int j = 1; j <= n; j++) lowcost[j] = G[1][j];
	int k;
	vis[1] = true;
	for (int i = 1; i <= n - 1; i++) {
        k = -1;
		int min = INF;
		for (int j = 1; j <= n; j++) {
			if (min> lowcost[j])
				if (!vis[j]) {
					k = j;
					min = lowcost[j];
				}
		}
		vis[k] = true;
		sum += lowcost[k];
		for (int j = 1; j <= n; j++)
			if (G[k][j] < lowcost[j] && !vis[j])
                lowcost[j] = G[k][j];
	}
	return sum;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int u,v,w;
    memset(G,0x3f,sizeof(G));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        if(G[u][v]>w) G[u][v]=G[v][u]=w;
    }
    printf("%d\n",prim(n));

    return 0;
}
