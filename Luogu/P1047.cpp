#include<iostream>
#include<cstdio>
using namespace std;

int L, m;
int a[11000];

int main() {
	scanf("%d%d", &L, &m);
	for (int i = 0; i <= L; i++) a[i] = 1;
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		for (int i = l; i <= r; i++) a[i] = 0;
	}
	int sum = 0;
	for (int i = 0; i <= L; i++)sum += a[i];
	cout << sum << endl;
	return 0;
}