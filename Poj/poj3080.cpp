#include<string.h>
#include<stdio.h>

void solve(char a[], char b[])
{
	int i, j, k;
	char t1[61] = { 0 }, t2[61] = { 0 };
	for (i = 0; i < strlen(a); i++)
	{
		for (j = 0; j < strlen(b); j++)
		{
			if (a[i] == b[j])
			{
				memset(t1, 0, sizeof(t1));
				int n, m, sum = 0;
				n = i;
				m = j;
				while (a[n] == b[m] && n<60 && m<60)
				{
					t1[sum] = a[n];
					sum++;
					n++;
					m++;
				}
				if (strlen(t1) > strlen(t2)) strcpy(t2, t1);
				else if (strlen(t1) == strlen(t2) && strcmp(t1, t2)<0) strcpy(t2, t1);
			}
		}
	}
	strcpy(a, t2);
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, i;
		scanf("%d", &m);
		getchar();
		char a[61] = { 0 }, b[61] = { 0 };
		gets(a);
		gets(b);
		solve(a, b);
		for (i = 1; i <= m - 2; i++)
		{
			gets(b);
			solve(a, b);
		}
		if (strlen(a) <3)printf("no significant commonalities\n");
		else puts(a);
	}

	return 0;
}