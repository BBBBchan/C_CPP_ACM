#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	char a[100];
	scanf("%s", a);
	for(int i = 0; i < strlen(a)-1; i++){
		if(a[i] == '-')
			printf("fu ");
		else if(a[i] == '0')
			printf("ling ");
		else if(a[i] == '1')
			printf("yi ");
		else if(a[i] == '2')
			printf("er ");
		else if(a[i] == '3')
			printf("san ");
		else if(a[i] == '4')
			printf("si ");
		else if(a[i] == '5')
			printf("wu ");
		else if(a[i] == '6')
			printf("liu ");
		else if(a[i] == '7')
			printf("qi ");
		else if(a[i] == '8')
			printf("ba ");
		else if(a[i] == '9')
			printf("jiu ");
	}
	int i =strlen(a)-1;
	if(a[i] == '0')
			printf("ling");
		else if(a[i] =='1')
			printf("yi");
		else if(a[i] =='2')
			printf("er");
		else if(a[i] == '3')
			printf("san");
		else if(a[i] == '4')
			printf("si");
		else if(a[i] == '5')
			printf("wu");
		else if(a[i] == '6')
			printf("liu");
		else if(a[i] == '7')
			printf("qi");
		else if(a[i] == '8')
			printf("ba");
		else if(a[i] == '9')
			printf("jiu");
	return 0;
}