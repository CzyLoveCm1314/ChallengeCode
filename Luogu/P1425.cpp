#include<cstdio>

int main() {
	int a[4];
	for (int i = 0; i < 4; i++)scanf("%d", &a[i]);
	int sum1 = a[0] * 60 + a[1];
	int sum2 = a[2] * 60 + a[3];
	printf("%d %d", (sum2 - sum1) / 60, (sum2 - sum1) % 60);
	return 0;
}