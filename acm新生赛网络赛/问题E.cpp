#include <stdio.h>
#include <string.h>
char a[100050];
int Q[100050];
int A[100050];
int main(){
    int Qcount = 0,Acount = 0;
    scanf("%s",a);
    for(int i = 0;i < strlen(a);i++){    
        if(a[i] == 'Q'-0)
            {Q[Qcount] = i;Qcount++;continue;}
        if(a[i] == 'A'-0)
            {A[Acount] = i;Acount++;continue;}
    }
    int x=1,small = 0,count = 0;
    long long int sum = 0;
    for(int i = 0;i < Acount; i++){
        int acount=1;
        if((i+1<Acount) && (A[i+1]<Q[x-1])){
            acount++;
            continue;
        }
        for(x =small;(Q[x] < A[i]) && x <Qcount;x++){
                small++;
        }        
        sum += acount*small*(Qcount - small);
    }
    printf("%lld",sum);
    return 0;
}