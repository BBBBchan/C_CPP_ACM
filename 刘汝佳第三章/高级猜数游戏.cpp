#include <stdio.h>
#include <string.h>
#define maxn 1010
int main()
{
	int n, a[maxn], b[maxn];
	int kase = 0;
	while(scanf("%d",&n) == 1 && n){					//输入序列长度，直到n=0时结束
		printf("Game %d:",++kase);						//游戏计数
		for(int i = 0;i < n; i++)	scanf("%d",&a[i]);	//输入标准序列,仅限1~9
			
		for(;;){
			int A = 0, B = 0;							//A代表位置正确，B代表除位置正确的数对外，正确的数字个数
			for(int i = 0; i < n; i++){
				scanf("%d",&b[i]);						//输入猜测序列
				if(a[i] == b[i])	A ++;
			}
			if(b[0] == 0)	break;						//输入全0序列结束
		
		for(int d = 1; d <= 9; d++){
			int c1 = 0, c2 = 0;
			for(int i = 0; i < n; i++){
				if(a[i] == d)	c1++;					//计算d在标准序列中出现的次数
				if(b[i] == d)	c2++;					//计算d在猜测序列中出现的次数
			}
			if(c1 < c2)		B += c1;					//若B每次加上同一个数在标准序列和猜测序列中出现次数少的次数，此时B中包含位置也正确的情况
			else	B += c2;
		}
		printf("	(%d,%d)\n",A, B-A);
		}
	}

}