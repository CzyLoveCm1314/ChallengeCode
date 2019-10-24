#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

typedef long long LL;
LL quickmod(LL a, LL b, LL mod) {
	LL res = 1;
	while (b > 0) {
		if (b & 1)res = res*a%mod;
		a = a*a%mod;
		b = b >> 1;
	}
	return res;
}
int str2int(string a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
		sum += a[i] - '0';
	return sum;
}
int main() {
	string a;
	cin >> a;

}