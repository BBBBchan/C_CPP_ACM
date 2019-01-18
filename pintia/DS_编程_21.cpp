#include <cstdio>
int a[100005] = {0}, ans[10005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--){
		int num, temp;
		scanf("%d", &num);
		for(int q = 0; q < num; q++){
			scanf("%d", &temp);
			if (num == 1)
				break;
			a[temp] = 1;
		}
	}
	int m;
	scanf("%d", &m);
	int count = 0;
	while(m--){
		int temp;
		scanf("%d", &temp);
		if(a[temp] != 1){
			ans[count] = temp;
			a[temp] = 1;
			count++;
		}
	}
	if(count != 0){
		for(int i = 0; i < count-1; i++)
			printf("%05d ", ans[i]);
		printf("%05d", ans[count-1]);
	}
	else
		printf("No one is handsome");
	return 0;
}