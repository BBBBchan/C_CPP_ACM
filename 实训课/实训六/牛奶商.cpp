#include <stdio.h>
struct p
{
	int price;
	int num;
}a[5000],temp;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a[i].price, &a[i].num);
	}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m-i-1; j++)
			if(a[j].price > a[j+1].price){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	int i = 0, ans = 0;
	while(n>0){
		n -= a[i].num;
		ans+= a[i].price*a[i].num;
		i++;
	}
	ans -= -1*n*a[i-1].price;
	printf("%d\n", ans);
	return 0;
}
