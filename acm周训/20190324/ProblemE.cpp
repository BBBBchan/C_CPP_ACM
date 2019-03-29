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
long long	n_Flag;
set<int>	s_Num;

int	main()
{
	while (scanf ("%lld", &n_TotNum) != EOF)
	{
		n_Flag	= 0;
		memset(n_NumA, 0, sizeof(n_NumA));
		memset(n_NumB, 0, sizeof(n_NumB));
		memset(n_Res, 0, sizeof(n_Res));

		for (int i = 1; i <= n_TotNum; i++)
		{
			scanf ("%lld %lld", &n_NumA[i], &n_NumB[i]);
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