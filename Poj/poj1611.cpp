#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

#define maxn 50000

int fa[maxn], a[maxn];
int ran[maxn];

void init(){
	int i;
	for (i = 1; i < maxn; i++)
	{
		fa[i] = i;
		ran[i] = 0;
	}
}

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int a, int b){
	int r1 = find(a);
	int r2 = find(b);
	if (r1 == 0) fa[r2] = r1;
	else if (r2 == 0) fa[r1] = r2;
	else fa[r1] = r2;
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF && (n + m)){
		init();
		int sum = 0, i, j, root, k, t;
		for (j = 0; j < m; j++){
			scanf("%d", &k);
			scanf("%d", &root);
			for (i = 1; i < k; i++){
				scanf("%d", &t);
				unite(t, root);
			}
		}
		for (i = 0; i < n; i++)
			if (find(i) == 0) sum++;
		printf("%d\n", sum);
	}
	return 0;
}