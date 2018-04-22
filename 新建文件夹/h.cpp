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
	memset(aws,0,sizeof(aws));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(scanf("%s", a)!=EOF){
	
	int x = strlen(a);
	for(int i = 0; i < x; i++)
		b[x-i-1] = a[i];
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
/*减法*/
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

	if(kase == -1)
		printf("YES\n");
	if(n == 0)
		printf("YES\n");
	if(n>=1){
		int isans = aws[n]*10+aws[0], first = 0,second=0;
		if(isans % 9 == 0)
				first = 1;
			n--;
			for(;n>0;n--){
				if(aws[n] != 9)
					break;
			}
			if(n==0)
				second = 1;
			if(second == 1&&first == 1)
				printf("YES\n");
			else printf("NO\n");
	}
	memset(aws,0,sizeof(aws));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
}
	return 0;

}