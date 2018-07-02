#include <stdio.h>
int main(){
	struct a{
		char name[20];
		int win;
		int equal;
		int lose;
		int goal;
		int loss;
	}a[32],k;
	int n, m;
	scanf("%d %d",&n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s %d %d %d %d %d",&a[i].name,&a[i].win,&a[i].equal,&a[i].lose,&a[i].goal,&a[i].loss);
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++)
			if((3*a[j].win + a[j].equal) < (3*a[j+1].win + a[j+1].equal)){
				 k = a[j];
				 a[j] = a[j+1];
				 a[j+1] = k;
			}			
}
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-i-1; j++)
			if((3*a[j].win + a[j].equal) == (3*a[j+1].win + a[j+1].equal))
				if((a[j].goal - a[j].loss) < (a[j+1].goal - a[j+1].loss)){
					k = a[j];
					a[j] = a[j+1];
					a[j+1] = k;
				}
	int p = 1;
	for(int i = 0; i < m; i++)
		printf("%d %s %d %d\n",p++,a[i].name,3*a[i].win + a[i].equal,a[i].goal - a[i].loss);
	
	return 0;
}
