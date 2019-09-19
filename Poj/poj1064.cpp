#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double a[10000],k ;
int n;
bool solve(double z)
{
	int i;
	double s = 0;
	for (i = 0; i < n; i++)
	{
		s +=(int)(  a[i] / z);
	}
	return s >= k;
}
int main()
{

	while (scanf("%d%lf", &n, &k) != EOF)
	{
	
		int i;
		for (i = 0; i < 10000; i++) a[i] = 0;
		for (i =0; i < n; i++)
			scanf("%lf", &a[i]);
		double max, head = -1, tail = 100000000;
		for (i = 1; i < 100; i++)
		{
			double temp = (head + tail) / 2;
			if (solve(temp) == 1)
			{
				max = temp;
				head = temp;
			}
			else tail = temp;
		}
		printf("%.2lf\n",floor(max*100)/100);
		
	}
}