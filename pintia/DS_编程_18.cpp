#include <cstdio>
int main(int argc, char const *argv[])
{
	int n, l;
	while(scanf("%d", &n) != EOF && n != 0){
		scanf("%d", &l);
		int a[1200] = {0};
		for(int i = 0; i < n; i++){
			int temp;
			scanf("%d", &temp);
			int j = 1;
			while(a[j] != 0){
				if(a[j] < temp ){
					j = j*2+1;
				}
				else if(a[j] >= temp){
					j = j*2;
				}
			}
			a[j] = temp;
		}
		for(int k = 0; k < l; k++){
			int b[1200] = {0};
			for(int i = 0; i < n; i++){
				int temp;
				scanf("%d", &temp);
				int j = 1;
				while(b[j] != 0){
					if(b[j] < temp){
						j = j*2+1;
					}
					else if(b[j] >= temp){
						j = j*2;
					}
				}
				b[j] = temp;
			}
			int kase = 1;
			for(int i = 0; i < 1200; i++){
				if(a[i] != b[i]){
					kase = 0;
					break;
				}
			}
			if(kase)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}