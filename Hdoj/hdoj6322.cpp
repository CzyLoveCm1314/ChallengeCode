#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d", &k);
		if (k == 1)printf("5\n");
		else printf("%d\n", k + 5);
	}
	return 0;
}