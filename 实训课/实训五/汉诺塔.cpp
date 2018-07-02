#include "stdio.h"
void hannoi (int n, char from, char buffer, char to){
    if (n == 0) return;
    hannoi (n-1, from, to, buffer);
    printf("%c --> %c\n", from, to);;
    hannoi (n-1, buffer, from, to);
}
int main(){
    int n;
    scanf("%d",&n);
    hannoi (n, 'A', 'B', 'C');
    return 0;
}