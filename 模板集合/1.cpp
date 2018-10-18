#include <iostream>
#include <string>
using namespace std;
int n;
void GetNext(char *P, int next[]){
    int p_len = n;
    int i = 0;   // P 的下标
    int j = -1;  
    next[0] = -1;
    while (i < p_len){
        if (j == -1 || P[i] == P[j]){
            i++;
            j++;
            if(P[i] != P[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }
}
int main(int argc, char const *argv[])
{
    char p[100];
    int next[100];
    scanf("%d%s", &n, p);
    GetNext(p,next);
    for(int i = 0; i < n; i++)
        printf("%d ", next[i]+1);
    return 0;
}