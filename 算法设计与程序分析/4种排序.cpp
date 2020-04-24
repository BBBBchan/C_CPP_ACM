#include <cstdio>
int a[10000], b[10000];
//快速排序
void quick_sort(int *a, int left, int right){
	if(left >= right)
		return;
	int i = left, j = right;
	int key = a[left];	// 选取最左边的为key
	//partition过程
	while(i < j){
		while(i < j && a[i] < key)
			i++;
		while(i < j && a[j] > key)
			j--;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	//左右区间分别进行递归
	quick_sort(a,left, i-1);
	quick_sort(a,i+1,right);
}
//冒泡排序
void BuluBulu(int *a, int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			//比较和交换
			if(a[i] > a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//选择排序
void select(int *a, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		// 寻找最小的值的下标
		for(int j = i+1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		//将剩下数组中最小的值存入对应首位
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}
//插入排序
void insert(int *a, int n){
	int key;
	for(int i = 1; i < n; i++){
		key = a[i];
		int j = i-1;
		//寻找数字可插入位置，并把数字向后移动
		while(j>=0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;//插入数字
	}
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	// 快速排序
	quick_sort(a,0, n-1);
	printf("After quick sort: \n");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int i = 0; i < n; i++){
		a[i] = b[i];
	}

	//冒泡排序
	BuluBulu(a, n);
	printf("After Bubble sort:\n");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int i = 0; i < n; i++){
		a[i] = b[i];
	}

	//选择排序
	select(a, n);
	printf("After select sort:\n"); 
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int i = 0; i < n; i++){
		a[i] = b[i];
	}

	//插入排序
	insert(a, n);
	printf("After insert sort:\n");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int i = 0; i < n; i++){
		a[i] = b[i];
	}
	return 0;
}