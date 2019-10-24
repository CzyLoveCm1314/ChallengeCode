#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int ans = 0;
	int temp = 0;
	int ansi, ansj, i, j;
	ansi = ansj = 0;
	i = j = 0;
	while (j < n) {
		if (temp + a[j] < 0) {
			temp = 0;
			j++; 
			i = j;
		}
		else if (temp + a[j] == 0) {
			temp += a[j++];
			i = j;
		}
		else if (temp + a[j]>0) {
			temp += a[j];
			if (ans < temp) {
				ansi = i;
				ansj = j;
				ans = temp;
			}
			j++;
		}
	}
	int flag = 0;
	int iszero = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) flag = 1;
		if (a[i] == 0)iszero = 1;
	}
	if (!flag&&iszero) printf("0 0 0\n");
	else if(!flag)printf("%d %d %d\n", ans, a[ansi], a[n-1]);
	else printf("%d %d %d\n", ans, a[ansi], a[ansj]);
	return 0;
}