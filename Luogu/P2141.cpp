#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a[200];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool vis[200]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[j]+a[k]==a[i] && j!=k)vis[i]=true;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		//cout<<vis[i]<<' ';
		if(vis[i])sum++;
	}
	cout<<sum<<endl;
	return 0;
}
