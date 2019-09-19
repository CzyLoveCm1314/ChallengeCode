#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;

vector<int> a;
int m, n;
int main() {
	scanf("%d%d", &m, &n);
	int t;
	int ans = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		if (find(a.begin(), a.end(), t) == a.end()) {
			a.push_back(t);
			ans++;
		}
		if (a.size() > m) 
			a.erase(a.begin());
	}
	printf("%d\n", ans);
	return 0;
}