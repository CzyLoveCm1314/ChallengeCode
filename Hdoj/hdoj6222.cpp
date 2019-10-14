#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

const int L = 11000;

string temp;
string mulsingle(string a, int b)
{
	int na[L];
	string ans;
	int La = a.size();
	fill(na, na + L, 0);
	for (int i = La - 1; i >= 0; i--) na[La - i - 1] = a[i] - '0';
	int w = 0;
	for (int i = 0; i<La; i++) na[i] = na[i] * b + w, w = na[i] / 10, na[i] = na[i] % 10;
	while (w) na[La++] = w % 10, w /= 10;
	La--;
	while (La >= 0) ans += na[La--] + '0';
	return ans;
}

string sub(string a, string b)
{
	string ans;
	int na[L] = { 0 }, nb[L] = { 0 };
	int la = a.size(), lb = b.size();
	for (int i = 0; i<la; i++) na[la - 1 - i] = a[i] - '0';
	for (int i = 0; i<lb; i++) nb[lb - 1 - i] = b[i] - '0';
	int lmax = la>lb ? la : lb;
	for (int i = 0; i<lmax; i++)
	{
		na[i] -= nb[i];
		if (na[i]<0) na[i] += 10, na[i + 1]--;
	}
	while (!na[--lmax] && lmax>0); lmax++;
	for (int i = lmax - 1; i >= 0; i--) ans += na[i] + '0';
	return ans;
}
string a[10000];
void init() {
	a[1] = "4";
	a[2] = "14";
	for (int i = 3; i<=56; i++) {
		a[i] = sub(mulsingle(a[i - 1], 4), a[i - 2]);
	}
}
string zzero(string a, int n) {
	string temp;
	for (int i = 1; i <= n - a.size(); i++)temp += '0';
	temp += a;
	return temp;
}
string DeletePreZero(string s){
	int i;
	for (i = 0; i<s.size(); i++)
		if (s[i] != '0') break;
	return s.substr(i);
}

int main(){
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> temp;
		for (int i = 1; i <= 56; i++)
			if (temp.size() <= a[i].size()) {
				temp = zzero(temp, a[i].size());
				//cout << temp << endl;
				if (temp <= a[i]) {
					cout << a[i] << endl;
					break;
				}
			}
	}
	return 0;
}