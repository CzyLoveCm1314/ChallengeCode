#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 50000 + 10;

int fa[maxn], a[maxn];
int ran[maxn];

void init() {
	int i;
	for (i = 1; i < maxn; i++) {
		fa[i] = i;
		ran[i] = 0;
	}
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int a, int b) {
	int r1 = find(a);
	int r2 = find(b);
	if (r1 == r2) return;
	if (ran[r1] < ran[r2]) fa[r1] = r2;
	else {
		fa[r2] = r1;
		if (ran[r1] == ran[r2]) ran[r1]++;
	}
}

int find_ans(int n)
{
	int i, sum = 0;
	for (i = 1; i <= n; ++i)
		if (fa[i] == i)
			++sum;
	return sum;
}

int main() {
	int i, n, m, a, b, test;    
	scanf("%d", &test);   
	while (test--) { 
		scanf("%d%d", &n, &m);        
		init();        
		for (i = 0; i<m; ++i) { 
			scanf("%d%d", &a, &b);
			unite(a, b); 
		}
		printf("%d\n", find_ans(n)); 
	}	
	return 0;
}