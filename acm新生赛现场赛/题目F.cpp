#include <stdio.h>
int main(){
 	int m,n;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		int rcount = 0,gcount =0,bcount=0;
		char a[n],b[n];			
		scanf("%s",a);
		scanf("%s",b);		
		for(int i = 0; i< n; i++)
			{
			if(a[i] == 'R'-0)
				rcount++;
			else if(a[i] == 'G'-0)
				gcount++;
			else if(a[i] == 'B'-0)
				bcount++;
				}
		for(int i = 0; i< n; i++)
			{
			if(b[i] == 'R'-0)
				rcount++;
			else if(b[i] == 'G'-0)
				gcount++;
			else if(b[i] == 'B'-0)
				bcount++;
				}
			if(rcount > n){
				printf("NO\n");
				continue;}
			if(rcount >=2){
				printf("YES\n");
				continue;
			}
			if(gcount == 0 || bcount ==0){
				printf("YES\n");
				}
			else 
				printf("NO\n");
	}
    return 0;
}
