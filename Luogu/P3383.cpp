#include<bits/stdc++.h>
using namespace std;

const int maxn=10000000+5;
bool isprime[maxn];

void init(int n){
    isprime[0]=isprime[1]=true;
    for(int i=2;i<=n;i++){
        if(!isprime[i]){
            if(i>n/i) continue;
            for(int j=i*i;j<=n;j+=i) isprime[j]=true;
        }
    }
}

int m,n;
int main(){
    scanf("%d%d",&n,&m);
    init(n);
    int t;
    for(int i=1;i<=m;i++){
        scanf("%d",&t);
        if(isprime[t]) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
