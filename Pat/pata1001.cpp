#include<iostream>
#include<cstdio>
#include<stack>
#include<cmath>
using namespace std;

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = a + b;
	int cnt = 0;
	int flag = 1;
	stack<char> s;
	if (ans == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (ans < 0)flag = 0;
	ans=abs(ans);
	while (ans>0) {
		if (cnt == 3) {
			cnt = 1;
			s.push(',');
			s.push(ans % 10+'0');
			ans /= 10;
		}
		else {
			cnt++;
			s.push(ans % 10 + '0');
			ans /= 10;
		}
	}
	if (!flag)cout << '-';
	while (!s.empty()) {
		char ch = s.top();
		s.pop();
		cout << ch;
	}

	return  0;
}