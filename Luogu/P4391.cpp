#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int n;
string str;
const int maxn = 1000000 + 10;
int Next[maxn];

void getNext(string str) {
	int i, j;
	Next[0] = -1;
	j = -1;
	for (i = 1; i < str.size(); i++) {
		while (j != -1 && str[i] != str[j+1]) j = Next[j];
		if (str[i] == str[j + 1])j++;
		Next[i] = j;
	}
}
int main() {
	cin >> n;
	cin >> str;
	getNext(str);
	cout << str.size() - Next[str.size()-1] -1 << endl;

	return 0;
}