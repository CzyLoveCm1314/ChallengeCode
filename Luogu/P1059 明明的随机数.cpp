#include<set>
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() > b.size();
	else return a > b;
}
vector<string> a, b;
int main() {
	int n;
	cin >> n;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		a.push_back(str);
		b.push_back(str);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < b.size(); i++) {
		if (a[0] == b[i]) {
			cout << i+1 << endl;
			cout << a[0] << endl;
			break;
		}
	}
	return 0;
}