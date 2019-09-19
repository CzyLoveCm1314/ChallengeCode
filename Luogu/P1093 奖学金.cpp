#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 400;
struct person {
	int gra[3];
	int id;
	bool operator <(const person &x) const {
		if ((gra[0] + gra[1] + gra[2]) != (x.gra[0] + x.gra[1] + x.gra[2])) return (gra[0] + gra[1] + gra[2]) > (x.gra[0] + x.gra[1] + x.gra[2]);
		else if (gra[0] != x.gra[0]) return gra[0] > x.gra[0];
		else return id < x.id;
	}
}a[maxn];
int n;
int main() {
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i].id = i;
		cin >> a[i].gra[0] >> a[i].gra[1] >> a[i].gra[2];
	}
	sort(a + 1, a + 1 + n);;
	for (int i = 1; i <= 5 && i <= n; i++) {
		cout << a[i].id << ' ' << a[i].gra[0] + a[i].gra[1] + a[i].gra[2] << endl;
	}
	return 0;
}