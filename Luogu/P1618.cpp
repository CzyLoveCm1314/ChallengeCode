#include<cstdio>
int b[3];
bool is3(int x) {
	int a[3];
	a[0] = x / 100;
	a[1] = x % 100 / 10;
	a[2] = x % 10;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (a[i] == a[j] || a[j] == 0) return false;
		}
	}
	return true;
}
bool is10(int x) {
	int a[10] = { 0 };
	int temp;
	for (int k = 0; k < 3; k++) {
		temp = b[k] * x;
		for (int i = 0; i < 3; i++) {
			if (a[temp % 10] == 1) return false;
			else {
				a[temp % 10]++;
				temp /= 10;
			}
		}
	}
	if (a[0] > 0)return false;
	return true;
}
int main() {
	scanf("%d%d%d", &b[0], &b[1], &b[2]);
	int flag = 1;
	for (int i = 0; i < 334; i++) {
		if (is3(i*b[0])) {
			if (is10(i)) {
				flag = 0;
				printf("%03d %d %d\n", i*b[0], b[1] * i, b[2] * i);
			}
		}
	}
	if (flag)printf("No!!!\n");

	return 0;
}