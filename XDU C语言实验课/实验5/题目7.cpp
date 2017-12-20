#include <stdio.h>
#include <string.h>
#define maxn 100
void sum(char *a, char *b,char *aws,int n,int m){
	int c[maxn],d[maxn];
	memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));  
	for(int i = 0; i < n; i++)
		c[i] = a[n-i-1]-'0';
	for(int i = 0; i < m; i++)
		d[i] = b[m-i-1]-'0';
	for(int i = 0; i < m || i < n; i++)
		aws[i] = c[i] + d[i];
	for(int i = 0; i < m || i < n; i++)
		while(aws[i] >= 10){
			aws[i] -= 10;
			aws[i+1] += 1;
		}
}
void minus(char *a,char *b,char *aws,int n,int m){
	int c[maxn],d[maxn];
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i = 0;i < n ; i++)
		c[i] = a[n-i-1]-'0';
	for(int i = 0; i < m; i++)
		d[i] = b[m-i-1]-'0';
	for(int i = 0; i < n; i++)
		aws[i] = c[i] - d[i];
	for(int i = 0;i < n; i++)
		while(aws[i] < 0){
			aws[i]+=10;
			aws[i+1]-=1;
		}
}
void mult(char *a,char*b,char*aws,int n,int m){
		int c[maxn],d[maxn];
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i = 0; i < n; i++)
		c[i] = a[n-i-1]-'0';
	for(int i = 0; i < m; i++)
		d[i] = b[m-i-1]-'0';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			aws[j+i] += c[i] * d[j];
			}
		for(int i = 0; i < m+n; i++)
			while(aws[i] >= 10){
				aws[i] -= 10;
				aws[i+1] +=1;
			}
	}
}
int jianfa(char *a,char *b,char*aws,int x,int y){
	int kase =0,k=0;
	if(x > y){					//大减小
		minus(a,b,aws,x,y);
	}
	else if(x < y){
		minus(b,a,aws,y,x);
		kase = 1;			//小减大
	}
	else {
		k = strcmp(a,b);
		if(k == 0)
			kase = -1;
		else if(k > 0)
			minus(a,b,aws,x,y);
		else{
			kase = 1;
			minus(b,a,aws,y,x);
		}					//位数相同
	}
	return kase;
}
int main(){
	char a[maxn],b[maxn];
	int n = maxn-1,kase =0,k=0,p = 0,q = 0;
	char aws[205];
/*加法*/
	memset(aws,0,sizeof(aws));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%s %s",&a,&b);
	int x = strlen(a);
	int y = strlen(b);
	if(a[0] == '-'){
		for(int i = 1; i < x;i++)
			a[i-1] = a[i];
		a[x-1] = 0;
		x--;
		p = 1;
	}
	if(b[0] == '-'){
		for(int i = 1; i < y;i++)
			b[i-1] = b[i];
		b[y-1] = 0;
		y--;
		q = 1;
	}
	if(p == 0&&q == 0){
		sum(a,b,aws,x,y);
	}
	else if(p == 0)
		kase = jianfa(a,b,aws,x,y);
	else if(q == 0)
		kase = jianfa(b,a,aws,y,x);
	else{
		printf("-");
		sum(a,b,aws,x,y);
	}
	while(aws[n] == 0){
		n--;
	}
	if(n == -1)
		kase = -1;
	if(kase == 1)
		printf("-");
	if(kase == -1)
		printf("0");
	for(;n>=0;n--)
	printf("%d", aws[n]);
	printf("\n");
/*减法*/
	memset(aws,0,sizeof(aws));
	kase = 0;
	if(p == 0 && q == 0)
		kase = jianfa(a,b,aws,x,y);
	else if(p == 0)
		sum(a,b,aws,x,y);
	else if(q == 0){
		kase = 1;
		sum(a,b,aws,x,y);
	}
	else
		kase = jianfa(b,a,aws,y,x);
	n = maxn-1;	
	while(aws[n] == 0){
		n--;
	}
	if(kase == 1)
		printf("-");
	if(kase == -1)
		printf("0");
	for(;n>=0;n--)
		printf("%d", aws[n]);

	printf("\n");
	memset(aws,0,sizeof(aws));
	kase = 0;
	if(p == q)
		mult(a,b,aws,x,y);
	else{
		kase = 1;
		mult(a,b,aws,x,y);
	}
	n = maxn-1;
	while(aws[n] == 0){
		n--;
	}
	if(n == -1){
		kase = 0;
		printf("0\n");
	}
	if(kase == 1)
		printf("-");
	for(;n>=0;n--)
	printf("%d", aws[n]);


	return 0;

}