#include<string>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int L = 1000;
string add(string a, string b)
{
	string ans;
	int na[L] = { 0 }, nb[L] = { 0 };
	int la = a.size(), lb = b.size();
	for (int i = 0; i<la; i++) na[la - 1 - i] = a[i] - '0';
	for (int i = 0; i<lb; i++) nb[lb - 1 - i] = b[i] - '0';
	int lmax = la>lb ? la : lb;
	for (int i = 0; i<lmax; i++) na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;
	if (na[lmax]) lmax++;
	for (int i = lmax - 1; i >= 0; i--) ans += na[i] + '0';
	return ans;
}

string a, b, c, d;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> a >> b >> c >> d;
		cout << add(add(a, b), add(c, d)) << endl;
	}
	return 0;
}