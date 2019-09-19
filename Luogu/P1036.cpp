#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[30];
int ans;
int n,k;

int isPrime(int x){
	if(x<2) return false;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}
void dfs(int step,int cnt,int x){
	if(cnt==k) {
		if(isPrime(x)) ans++;
		return;
	}
	if(step>n)return;
	dfs(step+1,cnt,x);
	dfs(step+1,cnt+1,x+a[step]);
}
int main(){
	ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans<<endl;
	
	return 0;
}
