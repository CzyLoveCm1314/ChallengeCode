#include<bits/stdc++.h>
using namespace std;

const int maxn=220000;
int n,t;
int a[maxn];
bool vis[maxn],tempvis[maxn];
int ans[maxn];
int minn=0x3f3f3f3f;

void dfs(int node,int num){
    if(vis[node])return;
    else if(tempvis[node]) minn=min(minn,num-ans[node]);
    else{
        tempvis[node]=true;
        ans[node]=num;
        dfs(a[node],num+1);
        vis[node]=true;
    }
}
int main(){
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(tempvis,0,sizeof(vis));
        dfs(i,0);
    }
    cout<<minn<<endl;
    return 0;
}
