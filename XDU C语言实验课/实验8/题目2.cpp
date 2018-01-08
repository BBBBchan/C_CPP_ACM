#include <stdio.h>
#include <string.h>
int main(){
	FILE *fin, *fout;
	fin = fopen("a.txt", "rb");
	fout = fopen("b.txt", "wb");
	char a[10000];
	while(fscanf(fin,"%s",a) != EOF){
	printf("%s\n", a);
	fprintf(fout, "%s\n", a);
	}
	fclose(fin);
	fclose(fout);
	int kase = 0;
	fout = fopen("b.txt","rb");
	while(fscanf(fout,"%s",a) != EOF){
		for(int i = 0; i < strlen(a); i++){
			if(a[i] == 'a')
				printf("Y\n");
				kase = 1;
				break;
		}
		if(kase == 1)
			break;
	}
	if(kase == 0)
		printf("N\n");
	return 0;
}