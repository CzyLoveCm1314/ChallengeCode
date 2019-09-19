#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int cnt = -1;
	int a, b;
	int mx = -1;
	for (int i = 1; i <= 7; i++) {
		scanf("%d%d", &a, &b);
		if (a + b > mx) {
			mx = a + b;
			cnt = i;
		}
	}
	printf("%d\n", cnt);
	return 0;
}