#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int s, d;
	while (scanf("%d%d", &s, &d) != EOF) {
		int ans = 0;
		if (4 * s < d) ans = 10 * s - 2 * d;
		else if (3 * s < 2 * d) ans = 8 * s - 4 * d;
		else if (2 * s < 3 * d) ans = 6 * s - 6 * d;
		else if (s < 4 * d) ans = 3 * s - 9 * d;
		else ans = -1;
		if (ans >= 0) printf("%d\n", ans);
		else printf("Deficit\n");
	}
	return 0;
}