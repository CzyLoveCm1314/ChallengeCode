#include<cstdio>
#include<cstring>
const int maxn=330000;
int n,m;
int c[maxn];
int la[maxn];

int lowbit(int x){
    return x&-x;
}

int getsum(int x){
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

void update(int x,int t){
    for(int i=x;i<=maxn;i+=lowbit(i))
        c[i]+=t;
}

int main(){
    int u,v;
    while(~scanf("%d",&n)){
        memset(c,0,sizeof(c));
        memset(la,0,sizeof(la));
        for(int i=1;i<=n;i++){
            scanf("%d%d",&u,&v);
            u++;
            la[getsum(u)]++;
            update(u,1);
        }
        for(int i=0;i<n;i++)printf("%d\n",la[i]);
    }
    return 0;
}
