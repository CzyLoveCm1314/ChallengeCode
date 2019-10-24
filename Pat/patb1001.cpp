#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	while (n != 1) {
		if (n & 1)n = (3 * n + 1) / 2;
		else n = n / 2;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}