#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1010;
char a[maxn];

int main() {
	//ios::sync_with_stdio(false);
	while (cin.getline(a,maxn)) {
		int len = strlen(a);
		for (int i = 0; i < len;) {
			if (i + 2 < len && a[i] == 'y' && a[i + 1] == 'o' && a[i + 2] == 'u') {
				printf("we");
				i += 3;
			}
			else {
				printf("%c", a[i]);
				i++;
			}
		}
		printf("\n");
	}
	return 0;
}