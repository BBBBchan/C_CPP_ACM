#include <stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int temp;
            scanf("%d",&temp);
            sum += temp;
        }
        sum /= n;
        printf("%d\n", sum);
    }
    return 0;
}