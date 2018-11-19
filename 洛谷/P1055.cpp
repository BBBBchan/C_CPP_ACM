#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	char a[20];
	int j = 1;
	int sum = 0;
	scanf("%s", a);
	for(int i = 0; i < 11; i++){
		if(a[i] == '-')
			continue;
		sum+=(a[i]-'0')*j;
		j++;
	}
	sum%=11;
	if(a[12]-'0'==sum || (a[12]=='X'&&sum==10))
		printf("Right");
	else{
		for(int i = 0; i < 12; i++)
			printf("%c", a[i]);
		if(sum!=10)
			printf("%d", sum);
		else
			printf("X");
	}
	return 0;
}