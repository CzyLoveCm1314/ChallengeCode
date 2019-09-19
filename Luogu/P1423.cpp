#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double x;
int main() {
	scanf("%lf", &x);
	double sum = 0;
	int i = 1;
	double temp = 2;
	do {
		sum += temp;
		temp =temp* 0.98;
		i++;
		//cout << sum << endl;
	} while (sum < x);
	cout << i-1<< endl;
	return 0;
}