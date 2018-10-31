#include <cstdio>
#include <cstring>
using namespace std;
struct {
    char p[100];
    int times[120];
}P[100];
int next[100];
/* P 为模式串，下标从 0 开始 */
void GetNext(char *P, int next[]){
    int p_len = strlen(P);
    int i = 0;   // P 的下标
    int j = -1;  
    next[0] = -1;
    while (i < p_len){
        if (j == -1 || P[i] == P[j]){
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
/* 在 S 中找到 P 第一次出现的位置，返回位置 */
int KMP(char *S, char *P, int next[]){
    int ans = 0;
    GetNext(P, next);
    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = strlen(S);
    int p_len = strlen(P);
    while (i < s_len){
        if (j == -1 || S[i] == P[j]){
            i++;
            j++;
        }
        else
            j = next[j];
        if (j == p_len){  // 匹配成功
            j = 0;
            ans++;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    char S[125];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        memset(P[i].times, 0, sizeof(int));
    }
    for(int i = 0; i < n; i++){
        scanf("%s", P[i].p);
     //   printf("%s\n", P[i].p);
    }
    int M;
    scanf("%d", &M);
    int k = 0;
    while(~scanf("%s",S)){
        k++;
        for(int i = 0; i < n; i++){
            P[i].times[k] = KMP(S,P[i].p, next);
        }
        if(k == M)
            break;
    }
    printf("%d\n", k);
    for(int i = 0; i < n; i++){
        printf("%s ", P[i].p);
        for(int j = 1; j <=k; j++)
            if(P[i].times[j] != 0)
                printf("(%d %d) ", j, P[i].times[j]);
        printf("\n");
    }
    return 0;
}