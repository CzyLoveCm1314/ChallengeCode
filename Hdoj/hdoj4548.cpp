#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
#define Max 1000010
bool prime[Max];
int is[Max];

void IsPrime()
{
	int i, j;
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i<Max; i++)
	{
		if (prime[i])
		{
			for (int j = i + i; j<Max; j += i)
				prime[j] = false;
		}
	}
	int sum = 0;
	for (i = 0; i < Max; i++)
	{
		int temp = 0;
		int t;
		t = i;
		while (t > 0)
		{	
			temp+= t % 10;
			t = t / 10;
		}
		if (prime[temp] != 0 && prime[i] != 0) sum++;
		is[i] = sum;
	}
}

int main()
{
	IsPrime();
	int cnt = 1;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int L, R,i;
		scanf("%d%d", &L, &R);
		printf("Case #%d: ",cnt++);
		printf("%d\n", is[R]-is[L-1]);
	}
	return 0;
}