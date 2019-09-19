#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	double n, p, k;
	while (scanf("%lf %lf", &n, &p) != EOF) {
		k = (double)pow(p, 1.0 / n);
		printf("%.0lf\n", k);
	}
}
