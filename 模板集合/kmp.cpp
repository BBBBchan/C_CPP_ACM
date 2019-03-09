#include <iostream>
#include <string>
using namespace std;
/* P 为模式串，下标从 0 开始 */
void GetNext(char *P, int next[]){
    int p_len = P.size();
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
    GetNext(P, next);
    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = S.size();
    int p_len = P.size();
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
