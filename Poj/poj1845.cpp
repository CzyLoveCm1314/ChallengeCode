#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;
const LL mod = 9901;
const int maxn = 10000;
int prime[maxn];
struct fac {
	int num;//质因子的值
	int times;//质因子的数量
}f[maxn];

int getprime(int n) {
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) prime[++prime[0]] = i;
		for (int j = 1; prime[j] <= n / i; j++) {
			prime[i*prime[j]] = 1;
			if (i%prime[j] == 0)break;
		}
	}
	return prime[0];
}
LL quick_mod(LL a, LL n,LL mod) {
	LL res = 1;
	LL temp = a%mod;
	while (n) {
		if (n & 1) res = (res*temp) % mod;
		temp = temp*temp%mod;
		n >>= 1;
	}
	return res;
}

int getfactors(int a,int b) {
	int cnt = 0;//记录质因子的数量
	for (int i = 1; i <= prime[0] && a>1; i++) {
		if (a%prime[i] == 0) {
			int tol = 0;
			while (true) {
				if (a%prime[i] == 0) {
					tol++;
					a = a / prime[i];
				}
				else break;
			}
			f[cnt].num = prime[i];
			f[cnt++].times = tol*b;
		}
	}
	if (a != 1) {
		f[cnt].num = a;
		f[cnt++].times = b;
	}
	return cnt;
}

LL sum(LL p,LL n)  { 
	if (n == 0) return 1;
	if (n % 2) return (sum(p, n / 2)*(1 + quick_mod(p, n / 2 + 1,mod))) % mod;
	else return (sum(p, n / 2 - 1)*(1 + quick_mod(p, n / 2 + 1,mod)) + quick_mod(p, n / 2,mod)) % mod;
}
int solve(int a, int b) {
	int cnt = getfactors(a, b);
	LL res = 1;
	for (int i = 0; i < cnt; i++) {
		res = res*sum(f[i].num,f[i].times)%mod;
	}
	return res;
}
int main() {
	getprime(maxn);
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", solve(a, b));
	return 0;
}