#include<bits/stdc++.h>

const int maxn=110000;
int n;
int to[maxn],de[maxn],vis[maxn],ans[maxn];

void del(int now){
    vis[now]=true;
    de[to[now]]--;
    if(!de[to[now]]) del(to[now]);
}
int findcircle(int now,int num){
    ans[now]=num;
    if(ans[to[now]]) return num;
    else return ans[now]=findcircle(to[now],num+1);
}
int calc(int now) {
    if(ans[now]) return ans[now];
    else return ans[now] = calc(to[now]) + 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&to[i]);
        de[to[i]]++;
    }
    for(int i = 1; i <= n; i++) if(!de[i]&&!vis[i]) del(i);
    for(int i = 1; i <= n; i++) if(de[i]&&!ans[i]) findcircle(i,1);
    for(int i = 1; i <= n; i++) if(!de[i]&&!ans[i]) calc(i);
    for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}

