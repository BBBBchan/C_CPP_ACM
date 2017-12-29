#include <stdio.h>
#include <string.h>
int chazhao(char m,char a[]);
int panduan(char n,char c[],int m);

int main()
{
    int i, j, k=0;
    char m;
    char a[26], b[256], c[26];
    c[0]='\0';
    gets(a);
    gets(b);
    for(i=0;i<strlen(b);i+=2)
    {
        if(chazhao(b[i],a)&&panduan(b[i],b,i))
        {
            c[k]=b[i];
            k++;
        }
    }
    if(c[0]!='\0')
    {
        for(i=0;i<k-1;i++)
            for(j=0;j<k-i-1;j++)
                if(c[j]>c[j+1]){
                    m=c[j];
                    c[j]=c[j+1];
                    c[j+1]=m;
        }
    }
    if(c[0]!='\0')
        for(i=0;i<k;i++)
            printf("%c ",c[i]);
    else
        printf("No");
    getchar();
    
    
}
int chazhao(char m,char a[])
{
    int i=0;
    for(;i<strlen(a);i++)
        if(m == a[i])
            return 1;
    
    return 0;
}
int panduan(char n,char c[],int m)
{
    int i=0;
    for(;i<m;i+=2)
        if(n == c[i])
            return 0;
    
    return 1;
}
