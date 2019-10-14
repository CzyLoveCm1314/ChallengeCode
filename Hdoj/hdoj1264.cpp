#include<cstdio>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
int map[120][120];
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int a, b, c, d;
	int sum = 0;
	memset(map, 0, sizeof(map));
	while (cin >> a >> b >> c >> d) {
		if (a == -2) {
			printf("%d\n", sum);
			break;
		}
		if (a == -1) {
			printf("%d\n", sum);
			sum = 0;
			memset(map, 0, sizeof(map));
		}
		for (int i = min(a, c); i < max(a, c); i++) {
			for (int j = min(b, d); j < max(b, d); j++) {
				if (!map[i][j]) {
					map[i][j] = 1;
					sum++;
				}
			}
		}
	}

	return 0;
}