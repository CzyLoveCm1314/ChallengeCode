#include<iostream>
#include<cstdio>
using namespace std;

int k;
bool isprime(int x) {
	if (x <= 1)return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int main() {
	while (~scanf("%d", &k)) {
		int i = 3, flag = 0;
		if (!isprime(k)) {
			for (i = 3; i <= k; i++) {
				if (k%i == 0) {
					flag = 1;
					break;
				}
			}
			if (!flag)printf("0\n");
			else printf("%d\n", i - 1);
		}
		else printf("%d\n", k - 1);
	}

	return 0;
}