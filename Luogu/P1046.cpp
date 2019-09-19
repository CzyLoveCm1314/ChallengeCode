#include<iostream>
#include<cstdio>
using namespace std;
int a[10], x;
int main() {
	for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
	scanf("%d", &x);
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		if (x + 30 >= a[i])sum++;
	}
	cout << sum << endl;
	return 0;
}