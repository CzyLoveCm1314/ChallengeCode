#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n, s, a, b;
struct apple {
	int x, y;
	bool operator<(const apple &xx) const {
		return y < xx.y;
	}
}G[6000];
priority_queue<apple> q;
int main() {
	scanf("%d%d", &n, &s);
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &G[i].x, &G[i].y);
	}
	sort(G + 1, G + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n;i++){
		if (a + b >= G[i].x) {
			if (s >= G[i].y) {
				ans++;
				s -= G[i].y;
			}
			else break;
		}
	}
	printf("%d\n", ans);
	return 0;
}