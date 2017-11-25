//大数加法2  
#include<stdio.h>  
#include<string.h>  
#define M 80  
char s1[M],s2[M];  
int a[M],b[M],c[M];  
int main()  
{  
    int i,j,k,n,m;  
    while(scanf("%s%s",s1,s2)==2)  
    {   
        memset(c,0,sizeof(c));  
        n=strlen(s1);  
        m=strlen(s2);  
 
        for(i=0; i<n; i++)  
            a[i]=s1[n-i-1]-'0';  
        for(i=0; i<m; i++)  
            b[i]=s2[m-i-1]-'0';  


        if(a[n-1] != 45 &&b[m-1] !=45){
            if(n>m) k=n;  
            else k=m;  
        for(i=0; i<=k; i++)  
        {   
            c[i]+=a[i]+b[i];  
            if(c[i]>9)  
            {  
                c[i+1]++;  
                c[i]-=10;  
            }  
        }  
        i=k;  
        while(c[i]==0) i--;  
    }

        if(i<0) printf("0");  
        else  
        {
            for(; i>=0; i--)  
                printf("%d",c[i]);  
        }  
       
    }  
    return 0;  
}  