#include <cstdio>
#include <cstring>
char a[100];
void print(int s, int e){
		while(a[s] == '0')
			s--;
		if(s < e)
			printf("0");
		while(s >= e){
			printf("%c", a[s]);
			s--;
		}
}
int main(int argc, char const *argv[])
{
	scanf("%s", a);
	int len = strlen(a), kase = 0, pos = 0;
	for(int i = 0; i < len; i++){
		if(a[i] == '.'){
			pos = i;
			kase = 1;
		}
		else if(a[i] == '/'){
			pos = i;
			kase = 2;
		}
		else if(a[i] == '%'){
			pos = i;
			kase = 3;
		}
	}
	if(kase == 0){
		print(len-1,0);
	}
	else if(kase == 1){
		print(pos-1,0);
		printf(".");
		pos++;
		while(a[pos] == '0'){
			pos++;
		}
		if(pos != len)
			print(len-1,pos);
		else
			printf("0");
	}
	else if(kase == 2){
		print(pos-1,0);
		printf("/");
		print(len-1,pos+1);
	}
	else if(kase == 3){
		print(pos-1,0);
		printf("%%");
	}
	return 0;
}