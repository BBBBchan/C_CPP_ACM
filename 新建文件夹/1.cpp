#include <stdio.h>  
#include <math.h>  
  
int sushu(int n)  
{  
    int i,j;  
    for(i = 2;i <= sqrt(n + 1);i++)  
    {  
        if(!(n%i))  
            return 0;  
        break;  
    }  
    return 1;  
}  
  
int main()  
{  
    int a,b,N;  
    int i;  
    printf("Please input a number N: N >= 6 && N%2==0\n");  
    scanf("%d",&N);  
    if((N < 6) || (N & 1))  
    {  
        printf("Please input a correct number!\n");  
        return 0;  
    }  
    else  
    {  
        for(i = 2;i <= N/2;i++)  
        {  
            if(sushu(i) && sushu(N -i))  
                printf("%d = %d + %d\n",N,i,N-i);  
            break;        
        }  
          
    }  
    return 0;  
}