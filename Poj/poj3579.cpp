#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

#define MAXN 100010
ll a[MAXN];
ll b[MAXN];
int n,k;
bool solve(int d) 
{
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		cnt += (upper_bound(a + i, a + n, a[i] + d) - 1 - (a + i));
	}
	if (cnt >= k) return 1;
	else return 0;
}
int main()
{

	while (scanf("%d", &n) != EOF)
	{
		int i;
		for (i = 0; i < MAXN; i++)
		{
			a[i] = 0;
			b[i] = 0;
		}
		for (i = 0; i < n; i++) scanf("%lld", &a[i]);
		sort(a, a + n);
		k = n*(n-1)/2;
		if (k % 2 == 0) k = k / 2;
		else k = (k + 1) / 2;
		int head = -1, tail = a[n - 1] - a[0];
		while (tail - head > 1)
		{
			int mid = (tail + head) / 2;
			if (solve(mid)) tail = mid;
			else head = mid;
		}
		printf("%d\n", tail);
	}
	return 0;
}