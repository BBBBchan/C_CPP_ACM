#include <stdio.h>
#include <string.h>

int		n_Length;
int		n_Result;
int		n_TotLine;
char	s_Str[1001];

int main()
{
	scanf ("%d", &n_TotLine);

	while (scanf ("%s", s_Str) != EOF)
	{
		n_Result	= 0;
		n_Length	= strlen(s_Str);

		for (int i = 0; i < n_Length; i++)
		{
			n_Result	+= s_Str[i] - 'a';
		}

		printf ("%d\n", n_Result);
	}
	return 0;
}