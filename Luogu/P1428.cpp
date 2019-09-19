#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a[200];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int temp=0;
		for(int j=i-1;j>=1;j--){
			if(a[j]<a[i])temp++;
		}
		if(i==1)printf("%d",temp);
		else printf(" %d",temp);
	}
	
	
	return 0;
}
