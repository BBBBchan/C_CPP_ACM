#include<stdio.h>  
#include<string.h>  
#define M 80  
char s1[M],s2[M];  
int a[M],b[M];  
int main()  
{  
    int i,j,k,n,m;  memset(a,0,sizeof(a));
    while(scanf("%s%s",s1,s2))  
    {  
          
        n=strlen(s1);  
        m=strlen(s2);  
 
        for(i=0; i<n; i++)  
            a[i]=s1[n-i-1]-'0';  
        for(i=0; i<m; i++)  
            b[i]=s2[m-i-1]-'0';  

        if(n>m) k=n;  
        else k=m;  
        for(i=0; i<=k; i++)  
        {  
            a[i]=a[i]+b[i];  
            if(a[i]>9)  
            {  
                a[i+1]++;  
                a[i]%=10;  
            }  
        }  
        i=k;  
        while(a[i]==0) i--;  

        if(i<0) printf("0");  
        else  
        {  
            for(; i>=0; i--)  
                printf("%d",a[i]);  
        }  
       
    }  
    return 0;  
}  