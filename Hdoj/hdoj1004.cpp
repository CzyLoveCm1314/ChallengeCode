#include<map>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)break;
		map<string, int > ballon;
		ballon.clear();
		string a,MaxColor;
		while (n--)
		{
			cin >> a;
			ballon[a]++;
		}
		map<string, int >::iterator it;
		int max = 0;
		for (it = ballon.begin(); it != ballon.end(); it++)
		{
			if (it->second > max)
			{
				max = it->second;
				MaxColor = it->first;
			}
		}
		cout << MaxColor << endl;
	}
	return 0;
}