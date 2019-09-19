#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef struct node
{
	int x, y, dir;
}robit;
robit r[110];
bool s[110][110];
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int a, b, n, m;
int num[110], rep[110];
char act[110];
bool judge(int x, int y)
{
	if (x<1 || x>a || y<1 || y>b)
		return true;
	return false;
}
void solve()
{
	int x, y;
	for (int i = 1; i <= m; i++)
	{
		bool flag = true;
		if (act[i] == 'F')
		{
			s[r[num[i]].x][r[num[i]].y] = false;
			while (rep[i]--)
			{
				x = r[num[i]].x + dir[r[num[i]].dir][0];
				y = r[num[i]].y + dir[r[num[i]].dir][1];
				if (judge(x, y))
				{
					printf("Robot %d crashes into the wall\n", num[i]);
					flag = false;
					break;
				}
				if (s[x][y])
				{
					int k;
					for (k = 1; k <= n; k++)
						if (r[k].x == x&&r[k].y == y) break;
					printf("Robot %d crashes into robot %d\n", num[i], k);
					flag = false;
					break;
				}
				r[num[i]].x = x;
				r[num[i]].y = y;
				r[num[i]].dir = r[num[i]].dir;
			}
			s[x][y] = true;
		}
		rep[i] %= 4;
		if (act[i] == 'R')
			while (rep[i]--)
			{
				int mov = r[num[i]].dir - 1;
				if (mov == -1)  mov = 3;
				r[num[i]].dir = mov;
			}
		if (act[i] == 'L')
			while (rep[i]--)
			{
				int mov = r[num[i]].dir + 1;
				if (mov == 4)  mov = 0;
				r[num[i]].dir = mov;
			}
		if (!flag) break;
		if (i == m) printf("OK\n");
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char ch;
		memset(s, 0, sizeof(s));
		scanf("%d%d", &a, &b);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			cin >> r[i].x >> r[i].y >> ch;
			s[r[i].x][r[i].y] = true;
			if (ch == 'E') r[i].dir = 0;
			if (ch == 'N') r[i].dir = 1;
			if (ch == 'W') r[i].dir = 2;
			if (ch == 'S') r[i].dir = 3;
		}
		for (int i = 1; i <= m; i++)
			cin >> num[i] >> act[i] >> rep[i];
		solve();
	}
	return 0;
}
