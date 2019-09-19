#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int flag;
	if (n < 0) printf("-");
	queue<int> q;
	n = abs(n);
	while (n > 0) {
		q.push(n % 10);
		n /= 10;
	}
	int flag2 = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (flag2) {
			if (t == 0)continue;
			else {
				printf("%d", t);
				flag2 = 0;
			}
		}
		else printf("%d", t);
	}
	return 0;
}