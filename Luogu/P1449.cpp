#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

string str;
string temp;
stack<int> q;
int str2int(string x) {
	int sum = 0;
	for (int i = 0; i < x.size(); i++) sum = sum * 10 + x[i] - '0';
	return sum;
}
int main() {
	cin >> str;
	int i = 0;
	int sum = 0;
	int t1, t2;
	while (i < str.size()) {
		if (str[i] == '@')break;
		if (str[i] == '-') {
			t1 = q.top();
			q.pop();
			t2 = q.top();
			q.pop();
			q.push(t2-t1);
		}
		else if (str[i] == '+') {
			t1 = q.top();
			q.pop();
			t2 = q.top();
			q.pop();
			q.push(t1 + t2);
		}
		else if (str[i] == '/') {
			t1 = q.top();
			q.pop();
			t2 = q.top();
			q.pop();
			q.push(t2 /t1);
		}
		else if (str[i] == '*') {
			t1 = q.top();
			q.pop();
			t2 = q.top();
			q.pop();
			q.push(t1 * t2);
		}
		else if (str[i] == '.') {
			q.push(str2int(temp));
			temp.clear();
		}
		else temp += str[i];
		i++;
	}
	cout << q.top() << endl;
	return 0;
}