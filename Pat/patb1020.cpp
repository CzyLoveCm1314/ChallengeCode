#include <stdio.h>

int main()
{
	int N, D;
	scanf("%d%d", &N, &D);
	double a[2000][2];
	for (int i = 0; i<N; i++)
		scanf("%lf", a[i]);
	for (int i = 0; i<N; i++)
		scanf("%lf", a[i] + 1);

	double even[2000], R;

	for (int i = 0; i<N; i++)
		even[i] = a[i][1] / a[i][0];
	while (D>0)
	{
		double max = 0;
		int maxi;
		double sum = 0;
		for (int i = 0; i<N; i++)
		{
			if (even[i]>max) { maxi = i; max = even[i]; }
			sum += even[i];
		}

		if (sum == 0) break;
		if (D >= a[maxi][0]) { D -= a[maxi][0]; R += a[maxi][1]; }
		else { R += D / a[maxi][0] * a[maxi][1]; D = 0; }
		even[maxi] = 0;

	}
	printf("%.2lf", R);
	return 0;
}