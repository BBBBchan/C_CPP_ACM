#include <stdio.h>
int main(){
	int m;
	scanf("%d", &m);
	while(m!=0){
		int a[m];
		int ans = 0;
		for(int i = 0; i < m; i++){
			scanf("%d", &a[i]);
			ans^=a[i];
		}
		if(ans == 0)
			printf("0\n");
		else{
			int count = 0;
			for(int i = 0; i < m; i++){
				int temp = ans^a[i];
				if(temp < a[i])
					count++;
			}
			printf("%d\n", count);
		}
		scanf("%d", &m);
	}
	return 0;
}