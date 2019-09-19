#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

string str;
int p, q, r, s, t;
int flag;
int a[5];
int cnt;

void change(char i){
	for (int j = 0; j != 5; j++)
		a[j] = ((i >> j) & 00000001);
}
bool cal() {
	char c = str[cnt];
	bool w, x;
	cnt++;
	switch (c) {
		case 'p':return a[0];
		case 'q':return a[1];
		case 'r':return a[2];
		case 's':return a[3];
		case 't':return a[4];
		case 'N':return !cal();
		case 'K':w = cal(); x = cal(); return (w&&x);
		case 'A':w = cal(); x = cal(); return (w || x);
		case 'C':w = cal(); x = cal(); return (w <= x);
		case 'E':w = cal(); x = cal(); return (w == x);
		default:return 0;
	}
}
int main() {
	while (cin >> str&&str[0] != '0') {
		flag = 1;
		for (int i = 0; i < 32; i++) {
			cnt = 0;
			change(i);
			if (!cal()) { 
				flag = 0; 
				break; 
			}
		}
		if (flag) printf("tautology\n");
		else printf("not\n");
	}
	return 0;
}