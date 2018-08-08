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
		w =(int)(((1 + sqrt(5.0))/2.0)*z);
		if(w == x)
			printf("HA0da!\n");
		else
			printf("ShAnJ1！\n");}
		return 0;
}

	
