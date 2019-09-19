#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int p[30],w[30];
char s[1000];
int main() {
	int t , n;
	scanf("%d", &t);
	while (t--) {
		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
		p[0] = 0;
		int temp = p[0];
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			temp = p[i] - p[i - 1];
			for (int j = 1; j <= temp; j++) s[cnt++] = '(';
			s[cnt++] = ')';
		}
		for (int i = 0; i < cnt; i++) {
			if (s[i] == '(')continue;
			int sum = 1;
			int j = i - 1;
			int temp = sum;
			while (temp > 0 && j>=0) {
				if (s[j] == '(')temp--;
				else {
					temp++;
					sum++;
				}
				j--;
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
	return 0;
}