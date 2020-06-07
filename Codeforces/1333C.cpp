#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

typedef long long LL;
map<LL, int> mm;
vector<int> v;

LL getsum(int x) {
	LL ans = 0;
	for (LL i = 1; i <= x; i++)ans += i;
	return ans;
}
int main() {
	int n;
	LL t, sum;
	sum = 0;
	scanf("%d", &n);
	LL ans=0;
	mm[0] = 1;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t);
		sum += t;
		if (mm.count(sum) == 0) mm[sum] = 1;
		else {
			mm[sum]++;
			v.push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)ans += i;
	/*
	for (map<LL, int>::iterator it = mm.begin(); it!=mm.end();it++) {
		cout << it->first<<' '<<it->second << endl;
		if(it->first==0) ans -= getsum(it->second-1);
	}*/
	ans -= getsum(v.size()-1);
	printf("%lld\n", ans);
	return 0;
}