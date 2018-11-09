#include <cstdio>
int a[200];
int main(int argc, char const *argv[])
{
	int n,sum=0,k=0;
	scanf("%d", &n);
	for(k = 0; sum < n*n ; k++){
		scanf("%d", &a[k]);
		sum+=a[k];
	}
	int pos = 0;
	for(int i = 0; i < k; i++){
		for(int j = 0; j <a[i]; j++){
			if(pos == n){
				pos=0;
				printf("\n");
			}
			if(i%2==0)
				printf("0");
			else
				printf("1");
			pos++;
		}
	}
	return 0;
}