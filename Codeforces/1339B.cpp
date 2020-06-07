#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

const int maxn = 100000 + 10;
int a[maxn];
int main() {
	int t;
	int n;
	map<int, int> mm;
	scanf("%d", &t);
	while (t--) {	
		mm.clear();
		stack<int> s;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int i = 0;
		int j = n - 1;
		int cnt = 0;
		while (i <= j) {
			if (!cnt) {
				s.push(a[j]);
				j--;
				cnt = 1;
			}
			else {
				s.push(a[i]);
				i++;
				cnt = 0;
			}
		}
		int t = s.top();
		printf("%d", t);
		s.pop();
		while (s.size() != 0) {
			t = s.top();
			printf(" %d", t);
			s.pop();
		}
		printf("\n");
	}

	return 0;
}