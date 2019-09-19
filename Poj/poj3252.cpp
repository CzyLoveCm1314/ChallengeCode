#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 40;
int c[maxn][maxn];
int bin[maxn];

void init() {
	for (int i = 0; i <= 33; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j || i == j)c[i][j] = 1;
			else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	c[0][0] = 1;
}

int cal(int n) {
	if (n <= 1)return 0;
	int len = 0;
	while (n>0){
		if (n & 1)bin[len++] = 1;
		else bin[len++] = 0;
		n >>= 1;
	}
	int ans = 0;
	for (int i = len - 1; i > 0; i--){
		if (i % 2 == 0)ans += ((1 << (i - 1))) / 2;
		else  ans += ((1 << (i - 1)) - c[i - 1][(i - 1) / 2]) / 2;
	}
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i<len; i++){
		if (bin[i] == 0)cnt0++;
		else cnt1++;
	}
	if (cnt0 >= cnt1) ans++;
	cnt0 = 0;
	cnt1 = 1;
	for (int i = len - 2; i >= 0; i--){
		if (bin[i] == 1){
			for (int j = i; j >= 0 && j + cnt0 + 1 >= i - j + cnt1; j--)ans += c[i][j];
			cnt1++;
		}
		else cnt0++;
	}
	return ans;
}

int main() {
	init();
	int l, r;
	while (~scanf("%d%d", &l, &r)) {
		printf("%d\n", cal(r) - cal(l - 1));
	}
	return 0;
}