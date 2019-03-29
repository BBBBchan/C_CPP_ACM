#include <stdio.h>
#include <algorithm>
using namespace std;

class Pair
{
public:
	int	n_NumA;
	int	n_NumB;
	friend bool operator < (const Pair & p_A, const Pair & p_B);
	friend bool operator > (const Pair & p_A, const Pair & p_B);
}

bool operator  < (const Pair & p_A, const Pair & p_B)
{
	if (p_A.n_NumA > p_B.n_NumA)
	{
		return false;
	}

	else if (p_A.n_NumA == p_B.n_NumA)
	{
		return p_A.n_NumB < p_B.n_NumB;
	}

	return true;
}

bool operator > (const Pair & p_A, const Pair & p_B)
{
	if (p_A.n_NumA < p_B.n_NumA)
	{
		return false;
	}

	else if (p_A.n_NumA == p_B.n_NumA)
	{
		return p_A.n_NumB > p_B.n_NumB;
	}

	return true;
}