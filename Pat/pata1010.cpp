#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

string n1, n2; 
int tag, radix;
int trans(string str, int radix) {
	int ans = 0;

	return ans;
}
int main(){
	cin >> n1 >> n2 >> tag >> radix;
	string t;
	int N1, N2;
	if (tag == 2) {
		t = n1;
		n1 = n2;
		n2 = t;
	}
	N2 = trans(n2, 10);

	return 0;
}