#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<cmath>
using namespace std;

typedef long long LL;
const int maxn = 100000;
const int INF = 0x7fffffff;

int n;
int a[maxn];
int b[maxn];

int main() {
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	for (int i = 1;i <= k;i++)scanf("%d", &a[i]);
	int t;
	scanf("%d", &t);
	for (int i = 1;i <= t;i++)scanf("%d", &b[i]);
	int sum = 0;
	int j = 1;
	for (int i = 1;i <= k;i++) {
		for (int x = j;x <= t;x++) {
			if (b[x] == a[i]) {
				j = x;
				sum++;
			}
		}

	}
	cout << sum << endl;
	return 0;
}