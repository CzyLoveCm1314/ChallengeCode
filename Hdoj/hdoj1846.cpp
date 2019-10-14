#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n%(m+1) != 0) printf("first\n");
		else printf("second\n");
	}

	return 0;
}