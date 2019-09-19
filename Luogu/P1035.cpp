#include<iostream>
#include<cstdio>
using namespace std;

int k;
double sum;
int main() {
	scanf("%d", &k);
	int i = 1;
	while (sum <= k) {
		sum += double(1.0 / i);
		i++;
	}
	cout << i-1 << endl;
	return 0;
}