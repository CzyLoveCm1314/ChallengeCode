#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main() {
	queue<int>q;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)q.push(i);
	int cnt = 0;
	int flag = 1;
	while (!q.empty()) {
		if (cnt == m-1) {
			if (flag) {
				printf("%d", q.front());
				flag = 0;
			}
			else printf(" %d", q.front());
			q.pop();
			cnt = 0;
		}
		else {
			cnt++;
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
}