#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int maxn = 10000;
string str, tmp;
int n;

int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	cin >> str;
	for (int i = 0; i < n-1; i++) {
		cin >> tmp;
		int x = str.find(tmp[0]);
		str.erase(x, 1);
		str.insert(x, tmp);
	}
	for (int i = 0; i < str.size(); i++)
		if (str[i] != '*') cout << str[i];
	return 0;
}