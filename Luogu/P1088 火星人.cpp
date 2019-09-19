#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[20000];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) next_permutation(a, a + n);
	cout << a[0];
	for (int i = 1; i < n; i++)cout << ' ' << a[i];
	return 0;
}