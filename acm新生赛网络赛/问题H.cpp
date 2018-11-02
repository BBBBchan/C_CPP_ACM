#include<stdio.h>  
#include<string.h>  
#define M 105  
char s1[M],s2[M],s3[M],s4[M],s[M],c[M],d[M];  
void ss(char s1[],char s2[],int n,int m,char c[])  
{  
    int i,j,a[M],b[M];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));  
    for(i=0; i<n; i++)  
        a[i]=s1[n-i-1]-'0';  
    for(i=0; i<m; i++)  
        b[i]=s2[m-i-1]-'0';  
    for(i=0; i<n; i++)  
        c[i]=a[i]-b[i];  
    for(i=0;i<n;i++)  
      if(c[i]<0){  
            while(c[i]<0){  
              c[i+1]=c[i+1]-1;  
              c[i]+=10;
               
            }  
        }
}
int main(){  
    int n1,m1,n2,m2,i,j,k,kk1,kk2,x,y;  
    memset(s1,0,sizeof(s1));  
    memset(s2,0,sizeof(s2));
    memset(s3,0,sizeof(s3));
    memset(s4,0,sizeof(s4));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));  
    scanf("%s%s",s1,s2);
    scanf("%s%s",s3,s4);  
        n1=strlen(s1);  
        m1=strlen(s2);
        n2=strlen(s3);
        m2=strlen(s4);
        if(n1 < m1)    
        ss(s2,s1,m1,n1,c);
        else{
            k = strcmp(s1,s2);
            if(k == 0)
                c[0] = -1;
            else ss(s2,s1,m1,n1,c);
        }
        if(n2 < m2) 
        ss(s4,s3,m2,n2,d);
        else{
            k = strcmp(s3,s4);
            if(k == 0)
                d[0] = -1;
            else ss(s4,s3,m2,n2,d);
        }   
        kk1=m1;
        kk2=m2;
        while(c[kk1]==0 ) {kk1--;}
        while(d[kk2]==0 ) {kk2--;}
        x = kk1;
        y = kk2;
        if(x>y)
            printf("Ting");
        else if(y > x)
            printf("Yu");
        else{
            int i =x;
            while(i >=0  && (c[i] == d[i])){
                i--;
            }
            if(i < 0)
                printf("Excellent");
            else if(c[i] > d[i])
                printf("Ting");
            else
                printf("Yu");   
        } 
    return 0;  
}  