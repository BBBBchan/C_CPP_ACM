#include <stdio.h>
#include <string.h>

long long	n_TotCase;
long long	n_Length1;
long long	n_Length2;
long long	n_Ans;
long long	n_Count;
long long	n_Input;
long long 	n_Num1;
long long	n_Num2;
long long 	n_Data1[101];
long long 	n_Data2[101];

long long	n_GetLong()
{
	int			n_Ch	= getchar();
	long long	n_Ret	= 0;

	while (n_Ch > '9' || n_Ch < '0')
	{
		n_Ch	= getchar();
	}

	while (n_Ch >= '0' && n_Ch <= '9')
	{
		n_Ret	= n_Ret * 10 + n_Ch - '0';
		n_Ch	= getchar();
	}

	return n_Ret;
}

int main()
{
	scanf ("%lld", &n_TotCase);

	while (n_TotCase--)
	{
		n_Count		= 0;
		n_Length1	= 0;
		n_Length2	= 0;
		n_Num1		= n_GetLong();
		n_Num2		= n_GetLong();

		while (n_Num1)
		{
			n_Data1[n_Length1]	= n_Num1 % 2;
			n_Num1				>>= 1; 
			n_Length1++;
		}

		while (n_Num2)
		{
			n_Data2[n_Length2]	= n_Num2 % 2;
			n_Num2				>>= 1;
			n_Length2++;
		}

		for (int i = n_Length1 - 1, j = n_Length2 - 1;
			i >= 0 && j >= 0;
			i--, j--)
		{
			if (n_Data1[i] != n_Data2[j])
			{
				break;
			}

			n_Count++;
		}

		n_Ans	= n_Length1 + n_Length2 - 2 * n_Count;

		printf ("%lld\n", n_Ans);
	}

	return 0;
}