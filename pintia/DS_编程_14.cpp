#include <iostream>
#include <cmath>
using namespace std;
int check(int x){
	if(x == 1)
		return 0;
	if(x%2 == 0 && x!=2)
		return 0;
	for(int i = 3; i<=sqrt(x); i+=2)
		if(x%i==0){
			return 0;
		}
	return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	while(n--){
		int k;
		scanf("%d", &k);
		if(check(k))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
