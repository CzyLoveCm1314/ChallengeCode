#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
char p[100000];
int num = 0;
int l;
int work(int o, char *O, int I)
{
	char c, *D = O;
	if (o>0)
	{
		for (l = 0; D[l]; D[l++] -= 10)
		{
			D[l++] -= 120;
			D[l] -= 110;
			while (!work(0, O, l))
				D[l] += 20;
			p[num++] = ((D[l] + 1032) / 20);
		}
		//p[num++]=10;
	}
	else
	{
		c = o + (D[I] + 82) % 10 - (I>l / 2)*(D[I - l + I] + 72) / 10 - 9;
		D[I] += I<0 ? 0 : !(o = work(c / 10, O, I - 1))*((c + 999) % 10 - (D[I] + 92) % 10);
	}
	return o;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		num = 0;
		char s[1200]; s[0] = '0';
		scanf("%s", s + 1);
		if (strlen(s) % 2 == 1)
			work(2, s + 1, 0);
		else
			work(2, s, 0);
		if ((p[num - 1] - '0') % 2 == 1)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}

	return 0;
}
