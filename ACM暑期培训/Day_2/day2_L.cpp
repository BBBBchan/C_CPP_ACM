#include <stdio.h>
int main(){
	int m;
	scanf("%d", &m);
	while(m!=0){
		int a[m];
		int ans = 0;
		for(int i = 0; i < m; i++){
			scanf("%d", &a[i]);
			ans = ans^a[i];
		}
		if(ans == 0){
			printf("No\n");
		}
		else{
			printf("Yes\n");
			for(int i = 0; i < m; i++){
				int temp = ans^a[i];
				if(temp < a[i])
					printf("%d %d\n",a[i], temp );
			}
			scanf("%d", &m);
		}
	}
}