#include <cstdio>
int b[1000005];
int BinarySearch(int array[], int len, int value)
{
	if (array == NULL || len <= 0)
		return -2;
 
	int low = 0;
	int high = len - 1;
	while (low < high)
	{
		int mid = (high + low) / 2;
		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid;	
	}
	if (array[high] == value){
			return high;
		}
 
	return -2;
}

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		int num;
		scanf("%d", &num);
		printf("%d ", BinarySearch(b,n,num)+1);
	}
	return 0;
}