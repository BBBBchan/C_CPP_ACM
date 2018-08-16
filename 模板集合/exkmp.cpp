#include <stdio.h>
#include <string.h>
int next[10005];
char a[1000005],b[10005];
int ans;
void get_next(char *b){
    int b_len = strlen(b);
    int i = 0, j = -1;
    next[0] = -1;
    while(i < b_len){
        if(j == -1 || b[i] == b[j]){
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int kmp(char *a, char *b){
    get_next(b);
    int a_len = strlen(a);
    int b_len = strlen(b);
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < a_len && j < b_len){
        if(j == -1 || a[i] == b[j]){
            i++;
            j++;
        }
        else
            j = next[j];
        if(j == b_len){
            count++;
            j=next[j];
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s %s", b, a);
        int ans =kmp(a,b);
        printf("%d\n", ans);
    }
    return 0;
}