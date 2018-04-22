#include <stdio.h>
int main(){
	float n;
	scanf("%f", &n)
	float weight[n];
	float answer = 1e9;
	for(int i = 0; i < n; i++){
		scanf("%f", weight[i]);
		int p = 0;
		for(int j = 0; j < i; j++){
			p = (a[i]-a[j])/(i-j);
			if(p < 0)
				p = -1*p;
		}
		if(p < answer)
			answer = p;
	}
	return 0;

}