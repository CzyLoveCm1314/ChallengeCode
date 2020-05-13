#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int mi[50];
int check(int x) {
	for (int i = 0; i <= 30; i++)
		if (mi[i] == x) return i;
	return -1;
}

int main() {
	//cout << long long(pow(2,30))<<endl
	//cout << int(sqrt(999999999)) << endl;
	mi[0] = 1;
	for (int i = 1; i <= 30; i++) mi[i] = 2 * mi[i-1];
	for (int i = 1; i <= 30; i++) mi[i] -= 1;
	int t;
	long long n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		int k = 0;	
		for (int i = 2; i <= 30; i++) {
			if (n % mi[i] == 0) {
				printf("%d\n", n / mi[i]);
				break;
			}
		}
	}
	return 0;
}