#include<cstdio>
bool is3(int x) {
	int a[3];
	a[0] = x / 100;
	a[1] = x % 100 / 10;
	a[2] = x % 10;
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 3; j++) {
			if (a[i] == a[j] || a[j]==0) return false;
		}
	}
	return true; 
}
bool is10(int x) {
	int a[10] = { 0 };
	int temp;
	for (int k = 1; k <= 3; k++) {
		temp = k * x;
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
	for (int i = 100; i < 333; i++) {
		if (is3(i)) {
			if (is10(i)) {
				printf("%03d %d %d\n", i,2*i,3*i);
			}
		}
	}

	return 0;
}