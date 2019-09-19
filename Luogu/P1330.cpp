#include<bits/stdc++.h>
using namespace std;

const int maxn=10100;
int n,m,c[maxn],vis[maxn];
vector<int> G[maxn];
int cnt;

void dfs(int node,int color){
    //cout<<node<<' '<<color<<' '<<cnt<<endl;
    if(c[node]!=-1 && c[node]!=color){
        cout<<"Impossible"<<endl;
        exit(0);
    }
    if(c[node]==color) return;
    cnt++;
    //cout<<"cnt="<<cnt<<endl;
    c[node]=color;
    vis[node]=1;
    for(int i=0;i<G[node].size();i++) {
       // cout<<G[node][i]<<' '<<(color^1)<<endl;
        dfs(G[node][i],color^1);
    }

}

int main(){
    cin.sync_with_stdio(false);
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            memset(c,-1,sizeof(c));
            cnt=0;
            dfs(i,0);
            int temp=0;
            for(int i=1;i<=n;i++){
                if(c[i]==1)temp++;
            }
           // cout<<cnt<<' '<<temp<<endl;
            ans+=min(temp,cnt-temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}
