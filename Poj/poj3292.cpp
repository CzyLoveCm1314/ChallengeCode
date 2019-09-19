#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1e6 + 1000;
int h[maxn + 10];
int sum[maxn + 10];

void table() {
	memset(h, 0, sizeof(h));
	for (int i = 5; i <= maxn; i += 4) {
		for (int j = 5; j <= maxn / i; j += 4) {
			if (h[i] == 0 && h[j] == 0) h[i*j] = 1;
			else h[i*j] = -1;
		}
	}
	int cnt = 0;
	sum[1] = 0;
	for (int i = 2; i <= maxn; i++) {
		if (h[i] == 1)sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1];
	}
}

int main() {
	table();
	int h;
	while (scanf("%d", &h) != EOF&&h) {
		printf("%d %d\n", h, sum[h]);
	}
	return 0;
}