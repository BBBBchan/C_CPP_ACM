#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t,p;
	scanf("%d", &t);
	while(t--){
		scanf("%d",&p);
		for(int i = 0; i < p; i++){
			int j=0;
			for(; j < p-1; j++)
				printf("%d ",(i+j)%p);
			printf("%d\n",(i+j)%p);
		}
		for(int i = 0; i < p; i++){
			int j = 0;
			for(; j < p-1; j++)
				printf("%d ", (i*j)%p);
			printf("%d\n",(i*j)%p);
		}
	}
	return 0;
}