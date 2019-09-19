#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string str;
char q[400];
int main() {
	cin >> str;
	int cnt = 0;
	int flag = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '(' && str[i] != ')') continue;
		else if (str[i] == '(') q[cnt++] = '(';
		else {
			if (q[cnt-1] == '(') cnt--;
			else {
				flag = 1;
				break;
			}
		}
	}
	if (cnt > 0)flag = 1;
	if (!flag)printf("YES\n");
	else printf("NO\n");
	return 0;
}