#include<stdio.h>
int main(){
    int input,sum=0;
    int arr[10];
    for(int i=0;i<=9;i++){
        scanf("%d",&input);
        arr[i]=input%42;
        }
    for(int i=0;i<=9;i++){
        for(int j=i+1;j<=9;j++){
            if(arr[i]==arr[j])
            sum++;
        }
    }
    
    printf("%d",(10-sum));
    return 0;	
}

