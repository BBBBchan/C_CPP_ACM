#include <stdio.h>
int kase;
int is(int a, int b, int c){
	if(a == b && b == c)
		return 1;				//1
	else if(a+1==b && b+1==c)
		return 2;				//2
	else if(a==b||b==c||a==c){
		if(a == b)
			kase = 0;
		else if(b == c)
			kase = 1;
		return 3;				//3
	}
	else if(a==2&&b==3&&c==5)
		return 5;
	else return 4;				//4
}
int main(int argc, char const *argv[])
{	int t;
	scanf("%d",&t);
	while(t--){
	int a,b,c,temp;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){temp=a;a=b;b=temp;}
	if(a>c){temp=a;a=c;c=temp;}
	if(b>c){temp=b;b=c;c=temp;}
	if(is(a,b,c) == 1)
		printf("%d\n", 9-a+1);
	else if(is(a,b,c) == 2)
		printf("%d\n", 9+7-a);
	else if(is(a,b,c) == 3){
		if(kase == 0)	
			printf("%d\n", 8+7+(9-a)*8+9-c);
		else if(kase == 1)
			printf("%d\n",8+7+(9-b)*8+8-a);
	}
	else if(is(a,b,c) == 4|| is(a,b,c) == 5){
		int ans = 9+7+72;	
		if(is(a,b,c) == 5) 		ans -=9;
		if(b+1==c)	ans-=1;
		ans+=b-a-1;
		while(c-b-1){
			b++;
			if(b == c-1)	ans -=1;
			ans+= b-1;
		}
		while(9-c){
			c++;
			ans+=(c-1)*(c-2)/2-1;
		}
		printf("%d\n",ans);
	}
}
	return 0;
}
