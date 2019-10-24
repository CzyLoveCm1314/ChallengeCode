#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 10000;
int n[maxn];
void makeNext(const char P[], int next[]) //find index
{
	int q, k;
	int m = strlen(P);
	next[0] = 0;
	for (q = 1, k = 0; q < m; ++q)
	{
		while (k > 0 && P[q] != P[k]) k = next[k - 1];
		if (P[q] == P[k]) k++;
		next[q] = k;
	}
}

int main() {
	char s[] = "123123123123";
	makeNext(s, n);
	for (int i = 0; i < strlen(s); i++) cout << n[i]<<' ';


}
