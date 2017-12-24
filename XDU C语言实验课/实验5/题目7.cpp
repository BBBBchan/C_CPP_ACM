<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#define maxn 100
void sum(char *a, char *b,char *aws,int n,int m){	//加法的外部函数，只支持正数相加
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
void minus(char *a,char *b,char *aws,int n,int m){		//减法的外部函数，只能大数减小数且为正数
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
void mult(char *a,char*b,char*aws,int n,int m){		//乘法外部函数，只支持正数相乘
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
int jianfa(char *a,char *b,char*aws,int x,int y){		//为减法调整顺序，使得两个正数相减时，总是大数减小数
	int kase =0,k=0;
	if(x > y){					//大数减小数
		minus(a,b,aws,x,y);		//在此调用减法的外部函数（在函数里调用函数）
	}
	else if(x < y){
		minus(b,a,aws,y,x);
		kase = 1;			//小数减大数
	}
	else {					//两个数位数相同时，比较大小并运算
		k = strcmp(a,b);
		if(k == 0)
			kase = -1;
		else if(k > 0)
			minus(a,b,aws,x,y);
		else{
			kase = 1;
			minus(b,a,aws,y,x);
		}					
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
	if(a[0] == '-'){				//读取负号
		for(int i = 1; i < x;i++)
			a[i-1] = a[i];
		a[x-1] = 0;
		x--;
		p = 1;
	}
	if(b[0] == '-'){				//读取负号
		for(int i = 1; i < y;i++)
			b[i-1] = b[i];
		b[y-1] = 0;
		y--;
		q = 1;
	}
	if(p == 0&&q == 0){			//加法情况下对出现负号的情况进行处理，即同正同负为加，一正一负为减
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
	while(aws[n] == 0){				//去除答案中前面不必要的0
		n--;
	}
	if(n == -1)
		kase = -1;
	if(kase == 1)
		printf("-");			//按情况输出负号
	if(kase == -1)
		printf("0");			//按情况得出0
	for(;n>=0;n--)
	printf("%d", aws[n]);		//输出结果
	printf("\n");
/*减法*/
	memset(aws,0,sizeof(aws));
	kase = 0;
	if(p == 0 && q == 0)				//通过判断符号进行适当处理，即同正同负为减法，一正一负为加法
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
	
/*乘法*/
	memset(aws,0,sizeof(aws));
	kase = 0;
	if(p == q)					//根据符号处理，即同正同负相乘，一正一负加符号
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

=======
#include <stdio.h>
#include <string.h>
#define maxn 100
void sum(char *a, char *b,char *aws,int n,int m){	//加法的外部函数，只支持正数相加
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
void minus(char *a,char *b,char *aws,int n,int m){		//减法的外部函数，只能大数减小数且为正数
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
void mult(char *a,char*b,char*aws,int n,int m){		//乘法外部函数，只支持正数相乘
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
int jianfa(char *a,char *b,char*aws,int x,int y){		//为减法调整顺序，使得两个正数相减时，总是大数减小数
	int kase =0,k=0;
	if(x > y){					//大数减小数
		minus(a,b,aws,x,y);		//在此调用减法的外部函数（在函数里调用函数）
	}
	else if(x < y){
		minus(b,a,aws,y,x);
		kase = 1;			//小数减大数
	}
	else {					//两个数位数相同时，比较大小并运算
		k = strcmp(a,b);
		if(k == 0)
			kase = -1;
		else if(k > 0)
			minus(a,b,aws,x,y);
		else{
			kase = 1;
			minus(b,a,aws,y,x);
		}					
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
	if(a[0] == '-'){				//读取负号
		for(int i = 1; i < x;i++)
			a[i-1] = a[i];
		a[x-1] = 0;
		x--;
		p = 1;
	}
	if(b[0] == '-'){				//读取负号
		for(int i = 1; i < y;i++)
			b[i-1] = b[i];
		b[y-1] = 0;
		y--;
		q = 1;
	}
	if(p == 0&&q == 0){			//加法情况下对出现负号的情况进行处理，即同正同负为加，一正一负为减
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
	while(aws[n] == 0){				//去除答案中前面不必要的0
		n--;
	}
	if(n == -1)
		kase = -1;
	if(kase == 1)
		printf("-");			//按情况输出负号
	if(kase == -1)
		printf("0");			//按情况得出0
	for(;n>=0;n--)
	printf("%d", aws[n]);		//输出结果
	printf("\n");
/*减法*/
	memset(aws,0,sizeof(aws));
	kase = 0;
	if(p == 0 && q == 0)				//通过判断符号进行适当处理，即同正同负为减法，一正一负为加法
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
	
/*乘法*/
	memset(aws,0,sizeof(aws));
	kase = 0;
	if(p == q)					//根据符号处理，即同正同负相乘，一正一负加符号
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

>>>>>>> ab67e1644e4f862a7dd9c21ca960764ed5c1ea53
}