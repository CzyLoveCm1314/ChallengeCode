#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	while (t--) {
		int n,a,b;
		scanf("%d%d%d", &n,&a,&b);
		char ss[2010] = {};
		for (int i = 0; i < a; i++) {
			ss[i] = s[i % b];
		}
		for (int i = 0; i < n; i++) {
			printf("%c", ss[i % a]);
		}
		printf("\n");
	}

	return 0;
}