#include<iostream>
#include<algorithm>
using namespace std;
int MIN(int a, int b)
{
	if (a < b)return a;
	else return b;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, i;
		cin >> n;
		int a[2000] = { 0 };
		for (i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		int ans = 0;
		int start = n;
		while (start)
		{
			if (start == 1)
			{
				ans += a[1];
				break;
			}
			else if (start == 2)
			{
				ans += a[2];
				break;
			}
			else if (start == 3)
			{
				ans += a[2] + a[1] + a[3];
				break;
			}
			else
			{
				ans += MIN(a[2] + a[1] + a[start] + a[2], a[start] + 2 * a[1] + a[start - 1]);
				start -= 2;
			}
		}
		cout << ans << endl;
	}
		
	
	return 0;
}