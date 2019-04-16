#include <stdio.h>
#include <string.h>

int		n_Count1;
int		n_Count2;
int		n_Count3;
int		n_Count4;
int 	n_Length;
int 	n_TotCase;
char	s_Str[6];

int main()
{
	scanf ("%d", &n_TotCase);

	for (int i = 1; i <= n_TotCase; i++)
	{
		n_Count2	= 0;
		n_Count4	= 0;
		for (int j = 1; j <= i + 1; j++)
		{
			scanf ("%s", s_Str);
			n_Length	= strlen(s_Str);
			n_Count1	= 0;
			n_Count3	= 0;

			for (int m = 0; m < n_Length; m++)
			{
				n_Count1	+= s_Str[m];
				n_Count3	+= s_Str[m] - 'a';
			}

			n_Count2	+= n_Count1;
			n_Count4	+= n_Count3;
			printf ("%d : %d (A) => %d\n", i, j, n_Count1);
			printf ("%d : %d (B) => %d\n", i, j, n_Count3);
		}

		printf ("%d Total => %d\n", i, n_Count2);
	}

	return 0;
}