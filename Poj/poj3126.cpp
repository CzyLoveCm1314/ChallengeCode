#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

int s, e;
bool vis[11000];

struct node {
	int n, step;
	node(int a,int b):n(a),step(b){}
};
bool isprime(int x) {
	if (x <= 1)return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int bfs() {
	queue<node> q;
	if (!isprime(s)) return 0;
	q.push(node(s, 0));
	vis[s] = 1;
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		if (t.n == e) return t.step;
		for (int i = 1; i <= 9; i += 2) {
			int x = t.n - t.n % 10 + i;
			if (!vis[x]&&isprime(x)) {
				vis[x] = 1;
				q.push(node(x, t.step + 1));
			}
		}
		for (int i = 0; i <= 9; i++) {
			int x = t.n/100*100 + t.n % 10 + i*10;
			if (!vis[x] && isprime(x)) {
				vis[x] = 1;
				q.push(node(x, t.step + 1));
			}
		}
		for (int i = 0; i <= 9; i++) {
			int x = t.n / 1000 * 1000 + t.n % 100 + i * 100;
			if (!vis[x] && isprime(x)) {
				vis[x] = 1;
				q.push(node(x, t.step + 1));
			}
		}
		for (int i = 1; i <= 9; i++) {
			int x =  t.n % 1000 + i * 1000;
			if (!vis[x] && isprime(x)) {
				vis[x] = 1;
				q.push(node(x, t.step + 1));
			}
		}
	}
	return -1;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &s, &e);
		memset(vis, 0, sizeof(vis));
		int cnt = bfs();
		if (cnt==-1)printf("Impossible\n");
		else printf("%d\n",cnt);
	}
	return 0;
}