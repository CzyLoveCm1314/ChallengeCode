#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
char T[maxn], P[maxn];

int main()
{
	while (~scanf("%s %s", P, T)){
		int lenP = strlen(P);
		int lenT = strlen(T);
		int i = 0, j = 0;
		while (i < lenT && j < lenP) {
			if (T[i] == P[j]) i++, j++;
			else i++;
		}
		if (j < lenP) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}