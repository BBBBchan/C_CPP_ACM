#include<stdio.h>
#include<string.h>
char a[100000];
char b[100000];
int c[1000000],d[1000000];
int sum = 0;
int main(){
    int ans[5][5]={2,1,0,1,0,0,2,1,0,1,1,0,2,1,0,0,1,0,2,1,1,0,1,0,2};
      scanf("%s",a);
      scanf("%s",b);
      for(int i=0;i<strlen(a);i++){
              if(a[i]=='S')     c[i]=0;
              else if(a[i]=='P')  c[i]=1;
              else if(a[i]=='R')  c[i]=2;
              else if(a[i]=='L')  c[i]=3;
              else if(a[i]='K')   c[i]=4;
              }
      for(int i=0;i<strlen(b);i++){
              if(b[i]=='S')       d[i]=0;
              else if(b[i]=='P')  d[i]=1;
              else if(b[i]=='R')  d[i]=2;
              else if(b[i]=='L')  d[i]=3;
              else if(b[i]='K')   d[i]=4;
              }
      for(int i = 0; i <= strlen(a)-strlen(b); i++){
        int temp = 0;
        for(int j = 0; j < strlen(b); j++){
          if(ans[d[j]][c[i+j]] == 1)
              temp++;
          if(temp + strlen(b)-j < sum)
              break;
        } 
        if(temp > sum)
          sum = temp;
    } 
      printf("%d\n", sum);
      return 0;
     }

     


