#include<iostream>
#include<cmath>
using namespace std;
int a[600000];
void init()
{
	int i,j;
	
}
int main()
{
	init();
	int n;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ans = 0, i, j;
		i = n;
			for (j = 1; j*j <= n; j++)
			{
				if (i%j == 0 && j != i / j) ans += j + i / j;
				if (i%j == 0 && j*j == i)ans += j;
			}
			ans -= i;
		cout << ans << endl;
	}
	return 0;
}