#include <stdio.h>
#include <math.h>
int main()
{	int x,y,temp,w,z;
	while(scanf("%d%d",&x,&y) == 2){
		if(x>y){
			temp = x;
			x = y;
			y = temp; 
		}
		z = y-x;
		w =(int)((1 + sqrt(5)/2)*z);
		if(w == x)
				printf("ShAnJ1£¡");
		else	printf("HA0da!");
			}
}

	
