/*
输入长度为n的单调不减的非负整数序列（可能相等）。
进行m次询问，对于每一次询问，给出一个整数q，要求输出改数字在序列中的变化，没有找到则输出-1.
*/
#include <cstdio>
int b[1000005];
//自定义的二分查找，针对重复数据进行改进，若有多个相同的数据，返回标号最小的
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