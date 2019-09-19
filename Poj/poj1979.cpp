#include<iostream>
#include<algorithm>
using namespace std;
int mark[21][21];
char map[21][21];
int ans = 1;
int w, h, x, y;
void solve(int n, int m)
{
	mark[n][m] = 1;
	if (mark[n][m + 1] != 1 && m + 1 <= w && map[n][m+1]=='.')
	{
		ans++;
		solve(n , m + 1);
	}
	if (mark[n - 1][m ] != 1 && n - 1 >0&& map[n - 1][m ] == '.')
	{
		ans++;
		solve(n - 1, m );
	}
	if (mark[n + 1][m] != 1 && n + 1 <= h && map[n + 1][m] == '.')
	{
		ans++;
		solve(n + 1, m );
	}
	if (mark[n][m - 1] != 1 && m - 1 >0 && map[n][m - 1] == '.')
	{
		ans++;
		solve(n , m - 1);
	}
	return;
}
int main()
{
	int i, j;
	while (cin >> w >> h)
	{
		for (i = 0; i <= 20; i++)
		{
			for (j = 0; j <= 20; j++)
			{
				map[i][j] = 0;
				mark[i][j] = 0;
			}
		}
		ans = 1;
		if (w == 0 && h == 0) break;
		for (i = 1; i <= h; i++)
		{
			for (j = 1; j <= w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		mark[x][y] = 1;
		solve(x, y);
		cout << ans << endl;
	}
	return 0;
}