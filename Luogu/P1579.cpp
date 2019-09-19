#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 1e5 + 1000;
int prime[maxn + 1];
void getprime() {
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= maxn; i++) {
		if (!prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= maxn / i; j++) {
			prime[prime[j] * i] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}

int main() {
	getprime();
	int n;
	scanf("%d", &n);
	bool flag = false;
	for (int i = 1; i <= prime[0]; i++) {
		if (flag)break;
		for (int j = i; j <= prime[0]; j++) {
			if (flag)break;
			for (int k = j; k <= prime[0]; k++) {
				if (prime[i] + prime[j] + prime[k] == n) {
					flag = true;
					printf("%d %d %d\n", prime[i], prime[j], prime[k]);
				}
			}
		}
	}


	return 0;
}
