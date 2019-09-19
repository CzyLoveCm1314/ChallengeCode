#include<cmath>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long gcd(long long a, long long b) {
	long long t;
	while (b) {
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	int n;
	scanf("%d", &n);
	long long  i = 1;
	while (i*(i + 1) / 2 < n) i++;
	long long  cnt = i;
	//cout << cnt << endl;
	long long  j = n - (i - 1)*i / 2;
	if(cnt%2==1) printf("%lld/%lld\n", (cnt - j + 1), j);
	else printf("%lld/%lld\n", j, (cnt - j + 1));
	return 0;
}