#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, x;
long long num[10];
int main() {
	scanf("%d%d", &n, &x);
	int temp;
	for (int i = 1; i <= n; i++) {
		temp = i;
		while (temp) {
			num[temp % 10]++;
			temp /= 10;
		}
	}
	cout << num[x] << endl;
	return 0;
}