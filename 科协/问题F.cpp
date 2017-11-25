#include <stdio.h>
int main(){
	int n;
	int a[4][4];
	scanf("%d",&n);
	for(;n>0;n--){
		int kase = 0;
		for(int i = 0;i<4;i++)
			for(int j = 0;j<4;j++)
				scanf("%d",&a[i][j]);
	
	// for(int i = 0;i<4;i++)
	// 	for(int j = 0;j<4;j++)
	// 		printf("%d ",a[i][j]);
		aa:for(int j = 0;j<4;j++){
			int i = 0;
			if(a[i][j] == 1)	continue;
			while((a[++i][j] != 1)&&i<4){			//down
				if(i == 3)	{kase++;goto aa;}
			}
			while(a[i][++j] != 1 &&j<4){
				if(a[i+1][j] == 0){
					while((a[++i][j] != 1)&&i<4){			//down
					if(i == 3)	{kase++;goto aa;}
					}
				}
			}

	}
	printf("%d\n",kase);
}
	return 0 ;
}