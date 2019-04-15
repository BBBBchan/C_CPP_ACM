#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	char a[15], b[15];
	int ans1=1,ans2 = 1;
	scanf("%s %s", a, b);
	for(int i = 0; i < strlen(a); i++){
		ans1 *= (a[i]-'A'+1);
	}
	for(int i = 0; i < strlen(b); i++){
		ans2 *= (b[i]-'A'+1);
	}
	ans1 = ans1%47;
	ans2 = ans2%47;
	if(ans2 == ans1){
		printf("GO\n");
	}
	else
		printf("STAY\n");
	return 0;
}