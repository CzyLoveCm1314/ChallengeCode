#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

double a[2000];
int main() {
	int t;
	memset(a, 0, sizeof(a));
	scanf("%d", &t);
	int k;
	double temp;
	while (t--) {
		scanf("%d%lf", &k, &temp);
		a[k] += temp;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lf", &k, &temp);
		a[k] += temp;
	}
	k = 0;
	for (int i = 0; i <= 1000; i++) {
		if (a[i] != 0.0) {
			k++;
		}
	}
	printf("%d", k);
	if (k != 0) printf(" ");
	for (int i = 1000; i >= 0; i--) {
		if (a[i] != 0.0) {
			printf("%d ", i);
			printf("%0.1f", a[i]);
			k--;
			if (k != 0) printf(" ");
		}
	}
	return 0;
}