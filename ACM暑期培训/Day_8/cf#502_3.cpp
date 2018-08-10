#include<stdio.h>
#include<math.h>
int a[100100];
int main(){
	int n,k,l,i,j;
	scanf("%d",&n);
	k = sqrt(n);
	l = 0;
	for (i=n;i>=1;i--) {
		l++;
		a[l]=i;
		if (l==k) {
			for (j=l;j>=1;j--)
				printf("%d ",a[j]);
			l=0;
		}
	}
		for (j=l;j>=1;j--) printf("%d ",a[j]);
} 