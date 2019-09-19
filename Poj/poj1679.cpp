#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge { 
	int u, v, w; 
} e[10005];
bool operator<(const Edge &a, const Edge &b) { 
	return a.w < b.w; 
}
int fa[105], mark[10005], re[10005];
int find(int i) { 
	return fa[i] == i ? i : fa[i] = find(fa[i]);
}
int kruskal(int n, int m, int d, int *f) {
	int ans = 0, i, sets = n;
	for (i = 1; i <= n; ++i) fa[i] = i;
	for (i = 0; i < m; ++i)
		if (i != d && find(e[i].u) != find(e[i].v)) {
			fa[find(e[i].u)] = find(e[i].v);
			ans += e[i].w; 
			--sets; 
			f[i] = 1;//这条边访问过
			if (sets == 1) break;
		}
	return sets == 1 ? ans : -1;
}
int main() {
	int n, m, t, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (i = 0; i < m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		sort(e, e + m); 
		memset(mark, 0, sizeof(mark));
		memset(mark, 0, sizeof(re));//满足传参而已
		int ans = kruskal(n, m, -1, mark);
		for (i = 0; i < m; ++i) {
			if (mark[i]) {
				if (kruskal(n, m, i, re) == ans) {
					puts("Not Unique!");
					break;
				}
			}
		}
		if (i == m) printf("%d\n", ans);
	}
	return 0;
}