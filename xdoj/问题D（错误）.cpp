#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1050
int compar( const void* a, const void* b )
{
    if( *(const int*)a > *(const int*)b ) return +1;
    if( *(const int*)a < *(const int*)b ) return -1;
    return 0;
}
int x[maxn][2];
int main(){
	memset(&x[0][0],1,sizeof(x));
	int t;
	scanf("%d",&t);
	while(t--){
		int a, b, c, n, k,q,p=0,l=0,kase=0;
		scanf("%d %d %d",&a,&b,&c);
		scanf("%d %d",&n,&k);
		x[0][0] = a;
		q = a;
		for(int i = 0; i < n; i++){
			q = ((q * b) + c)%1001;
			int m = p;
			for(;m>=0;m--){
				if(q == x[m][0])
					{x[p][1]++;kase++;break;}
			}
			if(!kase){x[p+1][0] = q;p++;}
		}
		qsort(x, sizeof(x)/sizeof(x[0]), sizeof(x[0]), &compar );
		int i = 0;
		for(;i<p;i++){
			l +=x[i][1];
			if(l > k)break;			
		}

		printf("%d",x[i][0]);
	}	
	return 0;
}