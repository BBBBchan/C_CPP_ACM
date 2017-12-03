#include<stdio.h>  
#include<string.h>  
char *sub(char a[], int n, char b[], int m) //大数相减  
{  
    int z=0;  
    for( ; n>=0; n--, m--)  
    {  
        if(m>=0)  
            a[n] = a[n] - b[m] + '0';  
        else  
            a[n] =  a[n];  
        if(a[n] < '0')  
        {  
            a[n] = a[n] +10;  
            a[n-1]--;  
        }  
    }  
    while(a[z] == '0')  
            z++;  
        a = a+z;  
        return a;  
}  
char *change(char a[], int n, char b[], int m)  
{  
    if(n>m)  
        a = sub(a, n, b, m);  
    if(n<m)  
    {  
        printf("-");  
        a = sub(b, m, a, n);  
    }  
    if(n==m)  
    {  
        if(strcmp(a, b) > 0)  
            a = sub(a, n, b, m);  
        else  
            if(strcmp(a, b) <0)  
        {  
            printf("-");  
        a = sub(b, m, a, n);  
        }  
            else  
                return "0";  
    }  
    return a;  
}  
int main()  
{  
    char a[100], b[100], *s;  
    int n, m;  
    printf("请输入被减数: ");  
    gets(a);  
    printf("\n\n请输入减数: ");  
    fflush(stdin);  
    gets(b);  
    n = strlen(a)-1;  
    m = strlen(b)-1;  
    printf("\n\n两数相减: ");  
    s = change(a, n, b, m);   
    puts(s);  
    printf("\n");  
}  
