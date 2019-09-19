#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int L = 1100000;
string a, b;
string sub(string a, string b){
	string ans;
	int na[L] = { 0 }, nb[L] = { 0 };
	int la = a.size(), lb = b.size();
	for (int i = 0; i<la; i++) na[la - 1 - i] = a[i] - '0';
	for (int i = 0; i<lb; i++) nb[lb - 1 - i] = b[i] - '0';
	int lmax = la>lb ? la : lb;
	for (int i = 0; i<lmax; i++){
		na[i] -= nb[i];
		if (na[i]<0) na[i] += 10, na[i + 1]--;
	}
	while (!na[--lmax] && lmax>0); lmax++;
	for (int i = lmax - 1; i >= 0; i--) ans += na[i] + '0';
	return ans;
}
string add(string a, string b){
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
bool judge(string a, string b) {
	if (a.size() != b.size()) return a.size()>b.size();
	else return a > b;
}
int main() {
	cin.sync_with_stdio(false);
	cin >> a >> b;
	if (a == b)cout << "0" << endl;
	else if (a[0] == '-') {
		if (b[0] != '-') cout << "-" << add(a.substr(1), b) << endl;
		else if (judge(a.substr(1), b.substr(1))) cout << "-" << sub(a.substr(1), b.substr(1)) << endl;
		else cout << sub(b.substr(1), a.substr(1)) << endl;
	}
	else if (b[0] == '-') cout << add(a, b.substr(1)) << endl;
	else if (judge(a, b))cout << sub(a, b) << endl;
	else cout << '-'<<sub(b,a) << endl;
	return 0;
}