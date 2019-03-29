#include <stdio.h>
#include <string.h>
#include <set>
#define SIZE 2501
using namespace std;

long long	n_NumA[SIZE];
long long	n_NumB[SIZE];
long long	n_Res[SIZE][3];
long long	n_Ans[SIZE];
long long	n_TotNum;
long long   cnt=0;
long long	n_Flag;
long long	n_IP;
set<int>	s_Num;

long long n_GetInt()
{
	long long	n_Ch		= getchar();
	long long	n_Ret		= 0;
	long long	n_Positive	= 1;

	while (n_Ch < '0' || n_Ch > '9')
	{
		if (n_Ch == '-')
		{
			n_Positive	= -1;
		}

		else if (n_Ch == EOF)
		{
			return EOF;
		}

		n_Ch	= getchar();
	}

	while (n_Ch >= '0' && n_Ch <= '9')
	{
		n_Ret	= n_Ret * 10 + n_Ch - '0';
		n_Ch	= getchar();
	}

	return n_Ret * n_Positive;
}

void v_Dfs(int n_Depth)
{
	if (n_Depth == n_TotNum + 1)
	{
		n_Flag	= 1;
		return;
	}
    cnt++;
    if (cnt>=2.5e6)
    {
    	n_IP	= 1;
    	return;
    }
	for (int i = 2; i >= 0; i--)
	{
		if (s_Num.find(n_Res[n_Depth][i]) == s_Num.end())
		{
			s_Num.insert(n_Res[n_Depth][i]);
			v_Dfs(n_Depth + 1);
			n_Ans[n_Depth]	= i;

			if (n_Flag)
			{
				break;
			}

			if (n_IP)
			{
				break;
			}

			n_Ans[n_Depth]	= 0;
			s_Num.erase(n_Res[n_Depth][i]);
		}
	}
}

int	main()
{
	while (scanf ("%lld", &n_TotNum) != EOF)
	{
		n_Flag	= 0;cnt=0;
		n_IP 	= 0;
		memset(n_NumA, 0, sizeof(n_NumA));
		memset(n_NumB, 0, sizeof(n_NumB));
		memset(n_Res, 0, sizeof(n_Res));

		for (int i = 1; i <= n_TotNum; i++)
		{
			n_NumA[i]	= n_GetInt();
			n_NumB[i]	= n_GetInt();
			n_Res[i][0]	= n_NumA[i] + n_NumB[i];
			n_Res[i][1]	= n_NumA[i] - n_NumB[i];
			n_Res[i][2]	= n_NumA[i] * n_NumB[i];
			
		}

		v_Dfs(1);

		if (n_Flag)
		{
			for (int i = 1; i <= n_TotNum; i++)
			{
				printf ("%lld ", n_NumA[i]);

				if (n_Ans[i] == 0)
				{
					printf ("+ ");
				}

				else if (n_Ans[i] == 1)
				{
					printf ("- ");
				}

				else if (n_Ans[i] == 2)
				{
					printf ("* ");
				}

				printf ("%lld = %lld\n", n_NumB[i], n_Res[i][n_Ans[i]]);
			}
		}

		else
		{
			printf ("impossible\n");
		}
	}
	return 0;
}