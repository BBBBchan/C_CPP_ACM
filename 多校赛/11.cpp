#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, a, b, c;
		scanf("%d", &n);
		if(n < 2){
			n++;
			while(n--)scanf("%d", &a);
			printf("Yes\n");
			continue;
		}
		if(n > 2){
			n++;
			while(n--)scanf("%d", &a);			
			printf("No\n");
			continue;
		}
		scanf("%d%d%d", &a, &b, &c);		
		if((b * b - 4 * a * c) >= 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}