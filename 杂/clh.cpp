#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	while(1){
		scanf("%d", &n);
		int sum	 = 0;
		if(n == 0)
			break;
		else{
			int temp;
			for(int i = 0; i < n; i++){
				scanf("%d", &temp);
				if((temp %2) == (n%2)){
					sum += temp;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}