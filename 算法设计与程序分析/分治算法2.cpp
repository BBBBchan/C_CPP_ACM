/*
求包含n个整数的数组A的第i小的数。
*/
#include <cstdio>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//与快速排序过程中的partition相同
int partition(int* a,int left,int right){
    int pivot = a[right];
    int i, j;
    i = left -1;
    for(j = left; j < right; j++)
    {
        if(a[j] < pivot)
        {
            i = i+1;
            swap(a+i, a+j);
        }
    }
    swap(a+i+1, a+right);
    return (i+1);
}
// 选择第k小
int select(int *a, int left, int right, int i){
	if(left == right){
		return a[left];
	}
	int p = partition(a,left,right);
	int j = p-left+1;
	if(i == j)
		return a[p];
	if(j < i)
		return select(a, p+1, right, i-j);
	else
		return select(a, left, p-1, i);
}
int a[100], n, i;
int main(int argc, char const *argv[]){
	scanf("%d %d", &n, &i);
	for(int j = 0; j < n; j++ ){
		scanf("%d", &a[j]);
	}
	printf("%d\n", select(a,0,n-1,i));
	return 0;
}