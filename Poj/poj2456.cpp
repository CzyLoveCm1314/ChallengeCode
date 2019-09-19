#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
int a[100000];
int n, m;
using namespace std;

int solve(int d)
{
	int last = 0;
	int i;
	for (i = 1; i < m; i++)
	{
		int x = last + 1;
		while (x < n && (a[x] < a[last]+d)) x++;
		if (x == n) return 0;
		last = x;
	}
	return 1;
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int i;
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		int head = 0, tail = 10000000;
		while (tail - head > 1)
		{
			int mid = (head + tail) / 2;
			if (solve(mid)==1) head = mid;
			else tail = mid;
		}
		printf("%d\n", head);
	}
	return 0;
}