#include <stdio.h>
int time = 100;
int magic1(int *i, int *j){
	return	*i += *j;
}

int magic2(int *i, int *j){
	*j = *i;
	return *i *= 2;
}
void dfs(int i, int j, int n, int times){
	if(i == n){
		if(times < time)
			time = times;
	}
	if(i < n){
		times++;
		dfs(magic2(&i,&j),j, n, times);
		dfs(magic1(&i,&j), j, n, times);
	//	while(i > n){
	//		i -= j;
	//	}
	//	int temp = j;
	//	times++;

	//	if(i > n){
	//		i /= 2;
	//		j = temp;
	//		times--;
	//	}
	}
	return ;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n,count = 0;
		time = 100;
		scanf("%d", &n);
		dfs(1,1,n,count);
		printf("%d\n", time);
	}

	return 0;
}
