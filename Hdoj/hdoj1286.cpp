#include<iostream>
#include<cmath>
using namespace std;
int  eular(int n)
{
	int i, ret = n;
	for (i = 2; i <= sqrt(n); i++) 
	{
		if (n%i == 0)
		{
			ret = ret / i*(i - 1);
			while (n%i == 0) n /= i;
		}
	}
	if (n>1) ret = ret / n*(n - 1);
	return ret;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout <<eular(n)<< endl;
	}
}