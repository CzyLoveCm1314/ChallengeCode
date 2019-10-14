#include<stdio.h>
#include<string.h>
char a[1000100];
int NEXT[1000100];
void getNext(char *s, int *next)
{
	int q, k;
	int m = strlen(s);
	next[0] = 0;
	for (q = 1, k = 0; q < m;q++)
	{
		while (k > 0 && s[q] != s[k]) k = next[k - 1];
		if (s[q] == s[k])k++;
		next[q] = k;
	}
}
int main()
{
	int n;
	int cnt = 1;
	while (scanf("%d", &n) != EOF&&n!=0)
	{
		getchar();
		memset(a, 0, sizeof(a));
		memset(NEXT,0, sizeof(NEXT));
		int i, j;
		gets(a);
		getNext(a, NEXT);
		printf("Test case #%d\n", cnt++);
		int m = strlen(a);
		for (int i = 0; i < m; i++)
		{
			if ((i +1)% (i - NEXT[i]+1) == 0 && (i+1) / (i - NEXT[i]+1) > 1)
				printf("%d %d\n", i+1, (i+1) / (i - NEXT[i]+1));
		}
		printf("\n");
	}
	return 0;
}