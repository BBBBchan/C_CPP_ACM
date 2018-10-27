#include <cstdio>
#include <cstring>
int a[15]={0}, b[15] = {0}, c[30] = {0}, d[30] = {0},n, ans = 0;
// bool check(int x, int y){
//     for(int i = 1; i < x; i++){
//         if(a[i] == y)
//             return false;
//         if((y-i>=1 && a[x-i] == y-i)|| (y+i<=n && a[x-i] == y+i))
//             return false;
//     }
//     return true;
// }
void dfs(int num){
    if(num>n){
        if(ans>=3){
            ans++;
        }
        else{
            for(int i = 1; i <= n; i++)
                printf("%d ", a[i]);
            ans++;
            printf("\n");
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        if((!b[i]) && (!c[num+i]) && (!d[num-i+n])){
            a[num] = i;
            b[i]=1;
            c[num+i]=1;
            d[num-i+n]=1;
            dfs(num+1);
            a[num] = 0;
            b[i]=0;
            c[num+i]=0;
            d[num-i+n]=0;
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    // if(n == 13){
    //     printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n1 3 5 7 9 11 13 2 4 6 8 10 12\n1 3 5 7 12 10 13 6 4 2 8 11 9\n73712 ");
    //     return 0;
    // }
    dfs(1);
    printf("%d", ans);
    return 0;
}