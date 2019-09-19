#include<bits/stdc++.h>

const int maxn=11000;
int fa[maxn],r[maxn];
int n,m;

void init(int n){
    for(int i=0;i<=n;i++){
        fa[i]=i;
        r[i]=0;
    }
}
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy) fa[xx]=yy;
}

int main(){
    int op,x,y;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)unite(x,y);
        else{
            if(find(x)==find(y)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
