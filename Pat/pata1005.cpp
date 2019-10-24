#include<cstdio>
#include<string>
#include<iostream>
#include<stack>
using namespace std;

string num[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

int main() {
	string str;
	getline(cin, str);
	int ans = 0;
	for (int i = 0; i < str.size(); i++) ans += str[i] - '0';
	stack<int> s;
	int t;
	while (ans > 0) {
		s.push(ans % 10);
		ans /= 10;
	}
	if (str == "0") {
		cout << num[0];
		return 0;
	}
	int flag = 0;
	while (!s.empty()) {
		t = s.top();
		s.pop();
		if (flag == 0) {
			cout << num[t];
			flag = 1;
		}
		else cout << ' ' << num[t];
	}
	return 0;
}