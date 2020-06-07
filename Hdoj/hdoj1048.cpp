#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1100;
char a[maxn];

int main() {
	while (cin.getline(a, maxn)) {
		if (strcmp(a, "START")==0 || strcmp(a, "END")==0) continue;
		if (strcmp(a, "ENDOFINPUT")==0)break;
		int len = strlen(a);
		for (int i = 0; i < len; i++) {
			if(a[i]<='Z'&&a[i]>='A')
				a[i] = (a[i] - 'A' + ('V' - 'A')) % 26 + 'A';
		}
		printf("%s\n", a);
	}
	return 0;
}