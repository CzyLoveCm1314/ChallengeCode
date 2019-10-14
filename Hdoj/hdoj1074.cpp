#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1 << 16;
const int INF = 0x3f3f3f3f;
int MAX(int a, int b)
{
	if (a > b)return a;
	else return b;
}
struct student
{
	string name;
	int ddl, day;
}a[20];
struct node1
{
	int time, pre, now, point;
}d[N];

void dfs(int t)
{
	if (t == 0) return;
	dfs(d[t].pre);
	cout << a[d[t].now].name << endl;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int i, j;
		memset(d, 0, sizeof(d));
		for (i = 0; i < n; i++)
		{
			cin >> a[i].name;
			scanf("%d%d", &a[i].ddl, &a[i].day);
		}
		int m = 1 << n;
		for (i = 1; i < m; i++)
		{
			d[i].point = INF;
			for (int j = n - 1; j >= 0; j--)
			{
				int t = 1 << j;
				if (t&i)
				{
					int past = i - t;
					int cost =MAX(0, d[past].time + a[j].day - a[j].ddl);
					if (cost + d[past].point<d[i].point)
					{
						d[i].point = d[past].point + cost;
						d[i].now = j;
						d[i].pre = past;
						d[i].time = d[past].time + a[j].day;
					}
				}
			}
		}
		printf("%d\n", d[m - 1].point);
		dfs(m - 1);
	}
	return 0;
}