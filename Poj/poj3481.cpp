#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<int, int> mp;

int main() {
	mp.clear();
	int n;
	while (scanf("%d", &n) != EOF&&n) {
		if (n == 1){
			int a, b;
			scanf("%d %d", &a, &b);
			mp[b] = a;
		}
		if (n == 2) {
			if (mp.size() == 0)printf("0\n");
			else {
				map<int, int>::iterator it = mp.end();
				it--;
				printf("%d\n", it->second);
				mp.erase(it);
			}
		}
		if (n == 3) {
			if (mp.size() == 0)printf("0\n");
			else {
				map<int, int>::iterator it = mp.begin();
				printf("%d\n", it->second);
				mp.erase(it);
			}
		}
	}
	return 0;
}