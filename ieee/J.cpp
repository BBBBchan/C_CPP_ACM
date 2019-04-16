#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define SIZE 20010
#define INF 0x3f3f3f3f3f

long long	n_TotEdge;
long long	n_TotBuild;
long long	n_TotVill;
long long	n_Value[SIZE];
int			n_InQue[SIZE];
int			n_First[SIZE];
int			n_Dis[SIZE];
int			n_Last[SIZE];
int			n_PrimeCnt;
int			n_Input;
long long	n_Multi[30];
int			n_Prime[30];
int			n_MaxVal	= -INF;
int			n_MinVal	= INF;
int			n_StartID;
int			n_EndID;
int			n_Mark[70];
queue<int>	q_Point;

struct Edge
{
	long long	n_Distance;
	int			n_ToPoint;
	int			n_NextEdgeID;
}e_Edge[SIZE << 1];

void v_MakeEdge(int n_From, int n_To, int n_Dis)
{
	n_TotBuild++;
	e_Edge[n_TotBuild].n_ToPoint	= n_To;
	e_Edge[n_TotBuild].n_NextEdgeID	= n_First[n_From];
	n_First[n_From]					= n_TotBuild;
	e_Edge[n_TotBuild].n_Distance	= n_Dis;

	n_TotBuild++;
	e_Edge[n_TotBuild].n_ToPoint	= n_From;
	e_Edge[n_TotBuild].n_NextEdgeID	= n_First[n_To];
	n_First[n_To]					= n_TotBuild;
	e_Edge[n_TotBuild].n_Distance	= n_Dis;
}

void v_Prime()
{
	for (int i = 2; i < 70; i++)
	{
		if (n_Mark[i])
		{
			n_PrimeCnt++;
			n_Prime[n_PrimeCnt]	= i;
		}

		for (int j = 1; j <= n_PrimeCnt; j++)
		{
			if (i * n_Prime[j] > 70)
			{
				break;
			}

			n_Mark[i * n_Prime[j]]	= 0;

			if (i % n_Prime[j] == 0)
			{
				break;
			}
		}
	}

	n_Multi[1]	= n_Prime[1];

	for (int i = 2; i < n_PrimeCnt; i++)
	{
		// printf ("%d\n", n_Prime[i]);
		n_Multi[i]	= n_Multi[i - 1] * n_Prime[i];

		if (n_Multi[i] > 1e18)
		{
			break;
		}
	}
}

void v_SPFA(int n_CurID)
{
	for (int i = n_First[n_CurID]; i; i = e_Edge[i].n_NextEdgeID)
	{
		if (n_InQue[e_Edge[i].n_ToPoint])
		{
			continue;
		}

		if (n_Dis[e_Edge[i].n_ToPoint] > n_Dis[n_CurID] + e_Edge[i].n_Distance)
		{
			n_Dis[e_Edge[i].n_ToPoint]		= n_Dis[n_CurID] + e_Edge[i].n_Distance;
			n_Last[e_Edge[i].n_ToPoint]		= n_CurID;
			n_InQue[e_Edge[i].n_ToPoint]	= 1;
			q_Point.push(e_Edge[i].n_ToPoint);
		}
	}

	n_InQue[n_CurID]	= 0;
	q_Point.pop();
	v_SPFA(q_Point.front());
}

long long	n_Gold(long long x)
{
	int	pos	= lower_bound(n_Multi+1, n_Multi+17, x) - n_Multi;
	return pos - 1;
}

int main()
{
	for (int i = 2; i < 70; i++)
	{
		n_Mark[i]	= 1;
	}

	v_Prime();

	scanf ("%lld %lld", &n_TotVill, &n_TotEdge);

	for (long long i = 1; i <= n_TotVill; i++)
	{
		scanf ("%lld", &n_Value[i]);

		if (n_MaxVal < n_Value[i])
		{
			n_MaxVal	= n_Value[i];
			n_EndID		= i;
		}

		if (n_MinVal > n_Value[i])
		{
			n_MinVal	= n_Value[i];
			n_StartID	= i;
		}

		n_Value[i]	= n_Gold(n_Value[i]);
	}

	for (long long i = 1; i <= n_TotEdge; i++)
	{
		int	n_FromID;
		int	n_ToID;

		scanf ("%d %d %d", &n_FromID, &n_ToID, &n_Input);
		v_MakeEdge(n_FromID, n_ToID, n_Input);
	}

	v_SPFA(n_StartID);

	printf ("%d\n", n_Dis[n_EndID]);

	return 0;
}