#include<cstdio>
typedef long long LL;
LL b, p, k;
LL quickmod(LL a, LL b, LL mod) {
	LL ans = 1;
	while (b) {
		if (b & 1)ans = ans*a%mod;
		b = b >> 1;
		a = a*a%mod;
	}
	return ans;
}
int main() {
	scanf("%lld%lld%lld", &b, &p, &k);
	if (p == 0)printf("%lld^0 mod %lld=%lld\n", b, k,1%k);
	else  printf("%lld^%lld mod %lld=%lld\n", b, p, k, quickmod(b, p, k));
	return 0;
}