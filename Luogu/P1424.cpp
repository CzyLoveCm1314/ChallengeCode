#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, x;
int main() {
	scanf("%d%d",&x, &n);
	int sum = 0;
	x--;
	for (int i = 1; i <= n; i++) {
		if (x == 7)x = 0;
		x++;
		if (x<=5 && x>=1)sum += 250;
	}
	cout << sum << endl;
	return 0;
}