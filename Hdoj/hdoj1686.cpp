#include<cstdio>
#include<cstring>
char str2[1000010];
char str1[100000];
int Next[100000];
void init()
{
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	memset(Next, 0, sizeof(Next));
}
void makeNext(const char P[], int next[])
{
	int q, k;
	int m = strlen(P);
	next[0] = 0;
	for (q = 1, k = 0 ; q < m; ++q)
	{
		while (k > 0 && P[q] != P[k]) k = next[k - 1];
		if (P[q] == P[k]) k++;
		next[q] = k;
	}
}
int kmp(const char T[], const char P[], int next[])
{
	int n, m;
	int i, q;
	n = strlen(T);
	m = strlen(P);
	int ans = 0;
	makeNext(P, next);
	for (i = 0, q = 0; i < n; ++i)
	{
		while (q > 0 && P[q] != T[i]) q = next[q - 1];
		if (P[q] == T[i]) q++;
		if (q == m) ans++;

	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		scanf("%s %s", str1, str2);
		printf("%d\n", kmp(str2, str1, Next));
	}
	return 0;
}