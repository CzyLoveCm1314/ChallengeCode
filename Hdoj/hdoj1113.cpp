#include<iostream>??
#include<stdio.h>??
#include<map>??
#include<string>??
#include<algorithm>??
using namespace std;

int main()
{
	string s;
	map<string, string> letter;
	letter.clear();
	while (cin >> s&&s != "XXXXXX")
	{
		string t=s;
		sort(s.begin(), s.end());
		letter.insert(pair<string, string>(t, s));
	}
	while (cin >> s)
	{
		if (s == "XXXXXX") break;
		int flag = 1;
		map<string, string>::iterator it;
		sort(s.begin(),s.end());
		for (it = letter.begin(); it != letter.end(); it++)
		{
			if (it->second == s)
			{
				flag = 0; 
				cout << it->first << endl;
			}
		}
		if (flag) cout<< "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}

