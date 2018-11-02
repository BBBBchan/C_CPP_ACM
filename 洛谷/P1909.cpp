#include <cstdio>
int main(int argc, char const *argv[])
{
	int n,min = 1e9+7, temp;
	int a,b;
	scanf("%d", &n);
	for(int i = 0; i < 3; i++){
		scanf("%d %d", &a, &b);
		if(n%a == 0){
			temp = (n/a)*b;
		}
		else{
			temp = (n/a+1)*b;
		}
		if(temp < min)
			min = temp;
	}
	printf("%d\n", min);
	return 0;
}