#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		map<string, map<string, int>> a;
		map<string, map<string, int>>::iterator it1;
		map<string, int>::iterator it2;
		string fruit, place;
		int num;
		while (m--)
		{
			cin >> fruit >> place>>num;
			a[place][fruit] += num;
		}
		for (it1 = a.begin(); it1 != a.end(); it1++) 
		{
			cout << it1->first << endl;
			for (it2 = (it1->second).begin(); it2 != (it1->second).end(); it2++) 
			{
				cout << "   |----" << it2->first << '(' << it2->second << ')' << endl;
			}
		}
		a.clear();
		if (n != 0) cout << endl;

	}
	return 0;

}