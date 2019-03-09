#include <stdio.h>
#include <string.h>
char a[100005];
int max = 0;
int main(int argc, char const *argv[])
{
	gets(a);
	int g = 0, p=0, l = 0, t = 0;
	for(int i = 0; i <strlen(a); i++){
		if(a[i] == 'G' || a[i] == 'g')
			g++;
		else if(a[i] == 'P' || a[i] == 'p')
			p++;
		else if(a[i] == 'L' || a[i] == 'l')
			l++;
		else if(a[i] == 'T' || a[i] == 't')
			t++;
	}
	while(g>0||p>0||l>0||t>0){
		if(g>0){
			printf("G");
			g--;
		}
		if(p>0){
			printf("P");
			p--;
		}
		if(l>0){
			printf("L");
			l--;
		}
		if(t>0){
			printf("T");
			t--;
		}
	}
	return 0;
}