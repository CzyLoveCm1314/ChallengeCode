#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
using namespace std;

const int maxn = 40;
double dis[maxn];
struct edge {
	int f, t;
	double c;
}es[maxn*maxn];
int n;
int cnt;
bool bellman(int v) {
	memset(dis, 0, sizeof(dis));
	dis[v] = 1;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= cnt; j++) {
			edge e = es[j];
			if (dis[e.t] < dis[e.f] * e.c){
				dis[e.t] = dis[e.f] * e.c;
			}
		}
	}
	for (int j = 1; j <= cnt; j++) {
		edge e = es[j];
		if (dis[e.t] < dis[e.f] * e.c) {
			return true;
		}
	}
	return false;
}
int main() {
	int c = 1;
	while (~scanf("%d", &n)&&n) {
		map<string, int> m;
		for (int i = 1; i <= n; i++) {
			string t;
			cin >> t;
			m[t] = i;
		}
		scanf("%d", &cnt);
		for (int i = 1; i <= cnt; i++) {
			string f, t;
			double c;
			cin >> f >> c >> t;
			es[i].f = m[f];
			es[i].t = m[t];
			es[i].c = c;
		}
		printf("Case %d: ", c++);
		for (int i = 1; i <= n; i++) {
			if (bellman(i)) {
				printf("Yes\n");
				break;
			}
			else if(i==n) printf("No\n");
		}
	}
	return 0;
}