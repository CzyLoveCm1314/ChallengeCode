#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int t,n;
int flag;
const int maxn=10;
string a[maxn];
int have[maxn];
int maxlen;
string ss="ACGT";

int cal(){
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,(int)a[i].size()-have[i]);
    return ans;
}

void dfs(int maxlen){
    int h=cal();
    if(h==0){
        flag=1;
        return;
    }
	int temp[maxn];
    if(h>maxlen) return;
    int flag2=0;
    memcpy(temp,have,sizeof(have));
	//Õâ¸öÕ¦Æ¥ÅäµÄ£¿
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            if(a[j][have[j]]==ss[i]){
                flag2=1;
                have[j]++;
            }
        }
        if(flag2){
            dfs(maxlen-1);
            if(flag) return ;
        }
        memcpy(have,temp,sizeof(have));
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        memset(have,0,sizeof(have));
        maxlen=-1;
        flag=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
			if ((int)a[i].size()>maxlen) maxlen = (int)a[i].size();
        }
        while(1){
            dfs(maxlen);
            if(flag)break;
            else maxlen++;
        }
        printf("%d\n",maxlen);
    }
    return 0;
}
