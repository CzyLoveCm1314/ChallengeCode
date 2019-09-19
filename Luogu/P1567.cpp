#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a[1010000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int j=1;
	int mx=-1;
	int temp=0;
	while(j<=n+1){
		if(a[j]>a[j-1])temp++;
		else{
			mx=max(mx,temp);
			temp=1;
		}	
		j++;
	}
	cout<<mx<<endl;
	return 0;
}
