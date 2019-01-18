#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n;
int ans = 0;
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
int KMP(char *S, char *P, int next[]){      //匹配位置
    GetNext(P, next);
    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = strlen(S);
    int p_len = strlen(P);
    while (i < s_len && j < p_len){
        if (j == -1 || S[i] == P[j]){
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j == p_len)  // 匹配成功
        return i - j; 
    return -1;
}
int KMP2(char *S, char *P, int next[]){         //求出现次数
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
            i -= p_len-1;
            ans++;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    char p[100], s[100];
    int next[100];
    scanf("%s %s", s, p);
    GetNext(p,next);
    int ans = KMP2(s,p,next);
    printf("%d\n", ans);
    for(int i = 0; i < n; i++)
        printf("%d ", next[i]+1);
    return 0;
}