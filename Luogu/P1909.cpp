#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct gift {
	int num, price;
}a[100000];
int main() {
	int n;
	scanf("%d", &n);
	int mx = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++) scanf("%d%d", &a[i].num, &a[i].price);
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i <= (int(n / a[k].num) + 1); i++) {
			if (a[k].num*i >= n) mx = min(a[k].price*i,mx);
		}
	}
	printf("%d\n", mx);
	return 0;
}