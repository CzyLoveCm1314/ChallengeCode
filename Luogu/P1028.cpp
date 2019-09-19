#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<cstdio>
using namespace std;
int ans;
int a[1010];
int dfs(int x) {
	if (x == 0)return 0;
	if (x == 1) return a[x]= 1;
	if (a[x] == 0) {
		int sum = 0;
		for (int i = 1; i <= x / 2; i++) sum += dfs(i);
		return a[x] = sum+1;
	}
	else return a[x];
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",dfs(n));
	return 0;
}
