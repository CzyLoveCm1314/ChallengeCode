#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int main() {
	int n, t,t1,t2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		q.push(t);
	}
	int ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		t1 = q.top();
		q.pop();
		t2 = q.top();
		q.pop();
		ans = t1 + t2+ ans;
		q.push(t1 + t2);
	}
	printf("%d\n", ans);
	return 0;
}