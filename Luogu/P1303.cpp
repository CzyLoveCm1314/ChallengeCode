#include<iostream>  
#include<cstring>  
#include<algorithm>  
#include<string>
using namespace std;
const int L = 31000;
string a, b;

string mul(string a, string b){
	string s;
	int na[L], nb[L], nc[L], La = a.size(), Lb = b.size();  
	fill(na, na + L, 0); fill(nb, nb + L, 0); fill(nc, nc + L, 0); 
	for (int i = La - 1; i >= 0; i--) na[La - i] = a[i] - '0';
	for (int i = Lb - 1; i >= 0; i--) nb[Lb - i] = b[i] - '0';
	for (int i = 1; i <= La; i++)
		for (int j = 1; j <= Lb; j++)
			nc[i + j - 1] += na[i] * nb[j];
	for (int i = 1; i <= La + Lb; i++)
		nc[i + 1] += nc[i] / 10, nc[i] %= 10;
	if (nc[La + Lb]) s += nc[La + Lb] + '0';
	for (int i = La + Lb - 1; i >= 1; i--)
		s += nc[i] + '0';
	return s;
}
string DeletePreZero(string s){
	int i;
	for (i = 0; i<s.size(); i++)
		if (s[i] != '0') break;
	return s.substr(i);
}


int main() {
	cin >> a >> b;
	if (a == "0"||b == "0") cout << "0" << endl;
	else if (a[0] == '-'&&b[0] == '-') cout << DeletePreZero(mul(a.substr(1), b.substr(1))) << endl;
	else if (a[0] == '-'&&b[0] != '-') cout << '-' << DeletePreZero(mul(a.substr(1), b)) << endl;
	else if (a[0] != '-'&&b[0] == '-') cout << '-' << DeletePreZero(mul(a, b.substr(1))) << endl;
	else cout << DeletePreZero(mul(a, b)) << endl;
	return 0;
}
