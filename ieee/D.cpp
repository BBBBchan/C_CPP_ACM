#include <stdio.h>

int			n_TotCase;
long long	n_A;
long long	n_B;
double		n_D;

long long n_FasterPow(long long n_Base, long long n_N)
{
	long long n_Ret		= 1;
	long long n_Multi	= n_Base;

	while (n_N)
	{
		if (n_N & 1)
		{
			n_Ret	= n_Ret * n_Base;
		}

		n_Base	= n_Base * n_Base;
		n_N 	>>= 1;
	}

	return n_Ret;
}

int main()
{
	scanf ("%d", &n_TotCase);

	while (n_TotCase--)
	{
		scanf ("%lld %lld", &n_A, &n_B);
		n_D	= n_FasterPow(2, n_B) / (double)n_A + 0.49999999999;

		printf ("%.0lf\n", n_D);

	}
	return 0;
}