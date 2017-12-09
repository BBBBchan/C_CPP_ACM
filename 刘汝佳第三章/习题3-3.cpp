#include <stdio.h>
#include <string.h>
char a[10005];
int count[10];
int main(){
	memset(count,0,sizeof(count));
	scanf("%s",a);
	int n = strlen(a);
	for(int i = 0; i < n; i++){
		switch (a[i]){
			case '0'-0:	count[0]++;	break;
			case '1'-0: count[1]++;	break;
			case '2'-0: count[2]++;	break;
			case '3'-0: count[3]++;	break;
			case '4'-0: count[4]++;	break;
			case '5'-0:	count[5]++;	break;
			case '6'-0:	count[6]++;	break;
			case '7'-0:	count[7]++;	break;
			case '8'-0:	count[8]++;	break;
			case '9'-0:	count[9]++;	break;
		}
	}
	for(int i = 0;i<10;i++)
		printf("%d ",count[i]);
	return 0;
}