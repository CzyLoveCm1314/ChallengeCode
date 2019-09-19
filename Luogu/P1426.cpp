#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
double s, x;

int main() {
	scanf("%lf%lf", &s, &x);
	double temp = 7;
	double sum = 0;
	int cnt = 0;
	while (sum <= s + x) {
		if (sum >= s - x&&sum <= s + x)cnt++;
		sum += temp;
		temp *= 0.98;
	}
	if (cnt > 1 )printf("y\n");
	else printf("n\n");

	return 0;
}