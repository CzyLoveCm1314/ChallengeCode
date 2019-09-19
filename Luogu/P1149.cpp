#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int a[10] = { 6,2,5,5,4,5,6,3,7,6 };
int num[10000];
int n;
int main() {
	scanf("%d", &n);
	num[0] = 6;
	for (int i = 1; i<=2000; i++) {
		int temp = i;
		while (temp) {
			num[i] += a[temp % 10];
			temp /= 10;
		}
	}
	int ans = 0;
	for (int i = 0; i<=1000; i++) {
		for (int j = 0; j<=1000; j++) {
			if (num[i] + num[j] + 4 + num[i + j] == n) {
				ans++;
				//cout << i << ' ' << j << ' '<<num[i]<<' '<<num[j]<<endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
