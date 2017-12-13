#include <stdio.h>
#include <string.h>
int main(){
 	int n;
 	while(scanf("%d",&n) != EOF)
 	{	
 		int il1=0,il2=0,xl1=0,xl2=0,cl1=0,cl2=0,m=0,d=0,c=0,l=0,x=0,v=0,i=0;
 		while(n>=1000){
 			n-=1000;
 			m++;
		 }
		 if(n>=900)
		 	{cl1++;
			n-=900;
			 }
		while(n>=500){
			n-=500;
			d++;
		}
		if(n>=400){
			cl2++;
			n-=400;
		}
		while(n>=100){
			n-=100;
			c++;
		}
		if(n>=90){
			n-=90;
			xl1++;
		}
		while(n>=50){
			n-=50;
			l++;
		}
		if(n>=40){
			xl2++;
			n-=40;
		}
		while(n>=10){
			n-=10;
			x++;
		}
		if(n>=9){
			il1++;
			n-=9;
		}
		while(n>=5){
			n-=5;
			v++;
		}
		if(n>=4){
			il2++;
			n-=4;
		}
		while(n>0){
			n-=1;
			i++;
		}
	 for(int p =0; p<m; p++){
	 	printf("M");}
	if(cl1 == 1)		printf("CM");
	for(int p = 0;p<d; p++){
		printf("D");
	}
	if(cl2 == 1)		printf("CD");
	for(int p = 0; p<c; p++){
		printf("C");
	}
	if(xl1 == 1)		printf("XC");
	for(int p = 0; p<l; p++){
		printf("L");
	}
	if(xl2 == 1)		printf("XL");
	for(int p = 0; p<x;p++)
	 	printf("X");
	if(il1 == 1)		printf("IX");
 	for(int p = 0; p<v; p++){
 		printf("V");
	 }
	if(il2 == 1)		printf("IV");
	for(int p = 0; p<i;p++){
		printf("I");
	} 
	printf("\n");
	 }
	
    return 0;
}
