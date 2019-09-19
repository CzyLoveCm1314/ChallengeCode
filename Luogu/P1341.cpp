#include<bits/stdc++.h>
using namespace std;

const int maxn=150;
int G[maxn][maxn];
int n;
string temp,ans;
int de[maxn];

void dfs(int node){
    for(int i='A';i<='z'+1;i++){
        if(G[node][i]>0){
            G[node][i]--;
            G[i][node]--;;
            dfs(i);
        }
    }
    ans+=char(node);
}
int main(){
    scanf("%d",&n);
    int cnt=0,start=0;
    for(int i=1;i<=n;i++){
        cin>>temp;
        G[temp[0]][temp[1]]++;
        G[temp[1]][temp[0]]++;
        de[temp[0]]++;
        de[temp[1]]++;
    }
    for(int i='A';i<='z';i++){
        if(de[i]%2){
            cnt++;
            if(!start)start=i;
        }
    }
    if(cnt!=0&&cnt!=2) cout<<"No Solution"<<endl;
    else if(cnt==0){
        start='z';
        for(int i='A';i<='z';i++){
            if(de[i]){
                start=i;
                break;
            }
        }
        dfs(start);
    }
    else dfs(start);
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
    return 0;
}
