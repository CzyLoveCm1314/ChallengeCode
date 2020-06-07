#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1010;
int a[maxn];
char s[maxn], temp[maxn];

int str2int(char s[]) {
	int len = strlen(s);
	int ans = 0;
	for (int i = 0; i < len; i++) {
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

int main() {
	while (scanf("%s", s) != EOF) {
		int cnt = 0;
		int index = 0;
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] != '5') temp[index++] = s[i];
			else {
				if (index > 0) {
					temp[index] = 0;
					a[cnt++] = str2int(temp);
					index = 0;
				}
			}
		}
		if (index > 0) {
			temp[index] = 0;
			a[cnt++] = str2int(temp);
			index = 0;
		}
		sort(a, a + cnt);
		for (int i = 0; i < cnt; i++) {
			if (i == 0)printf("%d", a[i]);
			else printf(" %d", a[i]);
		}
		printf("\n");
	}

	return 0;
}