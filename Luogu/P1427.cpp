#include<iostream>
#include<cstdio>
#include<stack> 
using namespace std;

stack<int> q;
int main() {
	int x;
	for(int i=0;;i++){
		scanf("%d",&x);
		if(x==0)break;
		q.push(x);
	}
	bool flag=false;
	while(!q.empty()){
		int t=q.top();
		q.pop();
		if(!flag){
			printf("%d",t);
			flag=true;
		}
		else printf(" %d",t);
	}
	return 0;
}
