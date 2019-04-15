#include <stdio.h>
long long int ans[1001], a[1001][1001], b[1001], g[1001] = {0};
void init(){
    ans[1] = 1;
    b[1] = 1;
    for(int i = 0; i <= 1000; i++)
        a[i][0] = 1;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= i; j++){
            a[i][j] = (a[i-1][j-1] + a[i-1][j]) % 1000000007;
        }
    }
    long long int temp = 1;
    for(int i = 2; i <= 1005; i++){
        for(int j = 1; j <= i-1; j++){
            g[i] = (g[i] + (a[i-1][j-1] *ans[j]) % 1000000007 * b[i-j]) % 1000000007;
        }
        temp = (temp*2) % 1000000007;
        b[i] = (temp*b[i-1]) % 1000000007;
        ans[i] = (b[i]-g[i] + 1000000007) % 1000000007;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    init();
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}