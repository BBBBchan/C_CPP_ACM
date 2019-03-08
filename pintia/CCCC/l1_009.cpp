#include <cstdio>
#include <cstdlib>
int GCD(int a,int b){
return b==0?a:GCD(b,a%b);
}
int ans_b = 1, ans_a = 0;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b;
		char temp;
		scanf("%d%c%d", &a, &temp, &b);
		int temp_a, temp_b;
		if(a > 0){
			temp_b = ans_b*b;
			temp_a = ans_a*b+ans_b*a;
			ans_a = temp_a/(GCD(temp_b,temp_a));
			ans_b = temp_b/(GCD(temp_b,temp_a));
		}
		else if(a < 0){
			temp_b = ans_b*b;
			temp_a = ans_a*b+ans_b*a;
			ans_a = temp_a/(GCD(temp_b, abs(temp_a)));
			ans_b = temp_b/(GCD(temp_b, abs(temp_a)));
		}
	}
	if(ans_b == 1)
		printf("%d", ans_a);
	else if(abs(ans_a) > ans_b && ans_a < 0)
		printf("%d %d/%d", ans_a/ans_b, abs(ans_a)-ans_b*(abs(ans_a)/ans_b), ans_b);
	else if(ans_a > ans_b && ans_a > 0)
		printf("%d %d/%d", ans_a/ans_b, ans_a-ans_b*(ans_a/ans_b), ans_b);
	else
		printf("%d/%d", ans_a, ans_b);
	return 0;
}