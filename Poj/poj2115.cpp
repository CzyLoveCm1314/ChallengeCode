#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long LL;
void exgcd(LL a, LL b, LL& d, LL& x, LL& y){
	if (!b) { 
		d = a; 
		x = 1;
		y = 0; 
	}
	else{
		exgcd(b, a%b, d, y, x);
		y -= x*(a / b);
	}
}

int main() {
	LL a, b, c, k;
	while (scanf("%lld%lld%lld%lld", &a, &b, &c, &k) != EOF) {
		if (a == 0 && b == 0 && c == 0 && k == 0)break;
		LL intmax = (1LL) << k;
		LL x, y, d;
		exgcd(c, intmax, d, x, y);
		if((b-a)%d) printf("FOREVER\n");
		else {
			LL t = intmax/ d;
			x = (((x*(b - a) / d) % t) + t) % t;
			printf("%lld\n", x);
		}
	}
	return 0;
}