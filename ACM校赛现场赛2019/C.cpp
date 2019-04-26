#include <cstdio>
#include <iostream>
using namespace std;
int a[3000005], b[3000005];
int main(int argc, char const *argv[])
{
	int n, now = 0;
	scanf("%d", &n);
	while(n--){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int temp;
			scanf("%d", &temp);
			a[now] = temp;
			if(now >= 1)
				b[now] = min(b[now-1],temp);
			else
				b[now] = a[now];
			now++;
		}
		else if(op == 2){
			if(now <= 0)
				printf("gg!\n");
			else
				now--;
		}
		else if(op == 3){
			if(now <= 0)
				printf("gg!\n");
			else
				printf("%d %d\n", b[now-1], a[now-1]);
		}
	}
	return 0;
}