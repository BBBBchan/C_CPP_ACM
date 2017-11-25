#include <stdio.h>
int main(){
	char ch ;
	char sh ;
	while ((ch = getchar()) != '#'){
		putchar(ch);
		while ((ch = getchar()) != '\n')
			continue;			

	}
	// ch = getchar() ;
	// putchar(ch);
	// char sh ;
	// printf("\n");
	// sh = getchar() ;
	// putchar(sh);
	// char eh ;
	// putchar(eh);
	return 0;


}

