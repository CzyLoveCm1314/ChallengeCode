#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

const int maxn = 1000000;
struct person {
	string id;
	int h1, h2, m1, m2, s1, s2;
}a[maxn];
bool cmp1(person a, person b) {
	if (a.h1 != b.h1) return a.h1 < b.h1;
	else if (a.m1 != b.m1) return a.m1 < b.m1;
	else if (a.s1 != b.s1) return a.s1 < b.s1;
}
bool cmp2(person a, person b) {
	if (a.h2 != b.h2) return a.h2 > b.h2;
	else if (a.m2 != b.m2) return a.m2 > b.m2;
	else if (a.s2 != b.s2) return a.s2 > b.s2;
}
int main() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].id;
		scanf("%d:%d:%d %d:%d:%d",&a[i].h1,&a[i].m1,&a[i].s1,&a[i].h2,&a[i].m2,& a[i].s2);
	}
	sort(a, a + m, cmp1);
	cout << a[0].id << ' ';
	sort(a, a + m, cmp2);
	cout<< a[0].id << endl;
	return 0;
}