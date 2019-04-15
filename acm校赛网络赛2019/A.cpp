#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	long long int a[1005];
	long long all=0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		all+=a[i];
	}
	if(all % n == 0){
		all /= n;
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			int temp;
			scanf("%d", &temp);
			if(a[temp] > all)
				printf("jian hao jiu shou!\n");
			else if(a[temp] < all)
				printf("ji shi zhi sun!\n");
			else if(a[temp] == all)
				printf("wei shi bu wan!\n");
		}
	}
	else{
		printf("you ren chu qian?\n");
	}

	return 0;
}