#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

struct person {
	int id, grade;
}a[6000];
bool cmp(person a, person b) {
	if (a.grade != b.grade)return a.grade > b.grade;
	else return a.id < b.id;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)cin >> a[i].id >> a[i].grade;
	sort(a + 1, a + 1 + n, cmp);
	m = m * 1.5;
	int cnt = m;
	int gra = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i].grade == a[m].grade)
		{
			m = i;
			break;
		}
	}
	cout << a[m].grade << ' ' << m << endl;
	for (int i = 1; i <= m; i++)
		cout << a[i].id << ' ' << a[i].grade << endl;
	return 0;

}