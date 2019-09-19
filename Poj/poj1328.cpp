#include<stdio.h>
#include<math.h>
struct island
{
	double left;
	double right;
	double x;
	double y;

};
int main()
{
	int n, s = 0;
	double d;
	struct island a[1002], temp;
	while (scanf("%d%lf", &n, &d) != EOF && (n != 0 || d != 0))
	{
		s++;
		int i, j, sum = 1;
		int flag = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &a[i].x, &a[i].y);
			a[i].left = a[i].x - sqrt(d*d - a[i].y*a[i].y);
			a[i].right = a[i].x + sqrt(d*d - a[i].y*a[i].y);
			if (a[i].y > d) flag = 1;
		}
		if (flag){
			printf("Case %d: -1\n", s);
		}
		else
		{
			for (i = 1; i < n; i++)
			{
				for (j = 1; j <= n - i; j++)
				{
					if (a[j].left > a[j + 1].left)
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
			double t;
			sum = 1;
			t = a[1].right;
			for (i = 2; i <= n; i++){
				if (a[i].right < t){
					t = a[i].right;
				}
				else if (a[i].left > t){
					sum++;
					t = a[i].right;
				}
			}
			printf("Case %d: %d\n", s, sum);
		}
	}
	return 0;
}